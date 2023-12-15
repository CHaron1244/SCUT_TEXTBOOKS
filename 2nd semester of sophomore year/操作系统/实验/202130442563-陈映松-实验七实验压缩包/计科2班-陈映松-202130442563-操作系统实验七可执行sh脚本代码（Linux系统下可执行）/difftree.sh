#!/bin/bash
# 比较两个目录的文件结构和文件内容
# 重点是利用了Linux中diff命令
if [ $# -ne 2 ]; then
  echo "ERROR! 您所输入的参数不是两个哟..."
  exit 1
fi

# 参数dir1 dir2用来记录传入的目录路径 
dir1="$1"
dir2="$2"

# 检查目录是否存在(用-d命令,存在则返回真)，再加上!表示取反
if [ ! -d "$dir1" ]; then
  echo "目录 '$dir1' 不存在哟..."
  exit 1
fi
if [ ! -d "$dir2" ]; then
  echo "目录 '$dir2 不存在哟..."
  exit 1
fi

# 比较目录结构:使用diff命令比较目录dir1和目录dir2的文件结构
# -q 仅报告文件是否有差异，不显示具体差异内容
# -r 选项指定递归比较
diff_output=$(diff -qr "$dir1" "$dir2")

# 这个if语句检查上一条diff命令的退出状态。如果退出状态($?)为0，表示目录结构相同，显示相应的消息
# 否则表示目录结构不同，显示不同结构的文件或子目录的详细信息。
if [ $? -eq 0 ]; then
  echo "哇!目录 '$dir1' 和 '$dir2' 结构居然一模一样!!!"
else
  echo "目录 '$dir1' 和 '$dir2' 在这些方面的结构不同:" # 用单引号时dir1 dir2不会被解析,原样输出
  echo "---------------------------------------"
  echo "$diff_output"
  echo "---------------------------------------"
fi

# 比较文件内容
# 条件含义:从find命令的输出中逐行读取文件路径,存储在file中,IFS= 确保读取的整行文本被保留
# read -r用于禁用特殊字符的转义，-d ''用于指定以空字符作为行分隔符
while IFS= read -r -d '' file 
do
  relative_path="${file#"$dir1"}" # 将文件路径中的dir1部分删除，得到相对路径
  file2="${dir2}${relative_path}" # 将dir2和相对路径组合起来，得到dir2下相应的文件路径
  
  if [ -f "$file2" ]; then # 判断file2是否存在
     # 使用diff命令比较文件file和file2的内容
    diff_output=$(diff -q "$file" "$file2") 
     
     # 判断那些同名的文件其内容是否完全一致
    if [ $? -eq 0 ]; then 
      echo "文件 '$file' 和 '$file2' 内容完全相同哟..."
    else
      echo "文件 '$file' 和 '$file2' 同名但内容不同哟..."
    fi
  fi
done < <(find "$dir1" -type f -print0) 
# 将 find命令的输出作为 while循环的输入
# type f 选项指定只匹配文件，而不是目录或其他类型的文件
# -print0 是 find 命令的一个选项，它指示 find 命令以空字符（null character）作为分隔符打印出文件路径

