#!/bin/bash
mycal(){
month=$1
year=$2

#先进行月份英文到数字的转化
case $month in
	"January") month=1
	;;		
	"February") month=2
	;;
	"March") month=3
	;;
	"April") month=4
	;;
	"May") month=5
	;;
	"June") month=6
	;;
	"July") month=7
	;;
	"August") month=8
	;;
	"September") month=9
	;;
	"October") month=10
	;;
	"November") month=11
	;;
	"December") month=12
	;;
esac

# 计算该月的第一天是星期几
#date -d "$year-$month-1" 表示显示year年month月第一天的日期，加上%u筛选出星期数
first_day_of_month=$(date -d "$year-$month-1" +%u)
#date -d "$year-$month-1" #调试部分
#echo "first_day_of_month = $first_day_of_month" #调试部分
# 计算该月的天数
days_in_month=$(date -d "$year-$month-01 + 1 month - 1 day" +%d)
#date -d "$year-$month-01 + 1 month - 1 day" 表示当月最后一天,加上%d筛选出天数
#date -d "1 month " 表示一个月之后的日期，date -d "1 month - 1 day" 表示一个月之后再回退一天的日期
#date +%d 输出当天日期
#echo "days_in_month = $days_in_month" #调试部分
# 打印月历表头
echo " Mo Tu We Th Fr Sa Su"
#echo " 一 二 三 四 五 六 日"

# 打印月历中第一行的空格(空格数为first_day_of_month-1)
for ((i=1; i<=$first_day_of_month-1; i++));do
 echo -n "   " #-n参数表示不自动换行
done

# 打印月历中的日期
for ((i=1; i<=$days_in_month; i++));do
  if [ $i -lt 10 ];then
    echo -n "  $i"
  else
    echo -n " $i"
  fi
  
  # 如果该行已经有了星期日，就换行打印下一行
  if [ $((($first_day_of_month + $i - 1) % 7)) -eq 0 ];then
    echo "" #这样子表示只是换行
  fi
done

# 如果最后一天不是星期日，就打印换行(这样做为了不让下一行命令行与最后一行日历同行)
if [ $((($first_day_of_month + $days_in_month - 1) % 7)) -ne 0 ];then
  echo ""
fi

}
