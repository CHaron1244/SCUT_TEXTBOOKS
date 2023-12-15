//sorted link list
template <class Elem, class Compare>
class SLList: protected LList<Elem> {  
public:
  SLList(int size=DefaultListSize) : LList<Elem>(size) {}
  ~SLList() {}                  // Destructor
   bool insert(const Elem& item) { // Insert at right
    Elem curr;
    for (setStart(); getValue(curr); next())
      if(!Compare::lt(curr, item)) break;
    return LList<Elem>::insert(item);
  }
template <class Elem>  HuffTree<Elem>*
buildHuff(SLList <HuffTree<Elem>*,HHCompare<Elem> >* f1) { 
    HuffTree<Elem>* temp1, *temp2, *temp3;
    for (f1->setStart(); f1->leftLength()+f1->rightLength()>1;
           f1->setStart())  {            //While at least two items left
        f1->remove(temp1);         //Pull first two trees off the list
        f1->remove(temp2);
        temp3 = new HuffTree<Elem>(temp1, temp2);
        f1->insert(temp3);             //Put the new tree back on list
        delete temp1;                     //Must delete the remnants
        delete temp2;                     //   of the trees we created
    }
    return temp3; }
  

