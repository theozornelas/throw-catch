#ifndef HEAP
#define HEAP

template <typename E>
class Heap : public CompleteBinaryTree<E>
{
public:
    /****************************
     * CONSTRUCTOR & DESTRUCTOR *
     ****************************/

    /************
     * MUTATORS *
     ************/
    void Insert(const E &newElement);
    void Remove();
    void HeapSort(QVector<E> &vecToSort, Comparator compare);

    /*************
     * ACCESSORS *
     *************/
    string PrintHeap();
    void GraphTree(string fileName,
                   string graphName) const;
    string GraphNode(int i)const;

    /**************
     * EXCEPTIONS *
     **************/
    class Empty{};

protected:

    /**************
     * ATTRIBUTES *
     **************/
    bool maxHeap = false; //True if the heap is a max heap

private:

    /*************
     * RECURSIVE *
     *************/
//	void Add(const E &newElement,
//			 int i);

    /*************
     * UTILITIES *
     *************/
    void FixHeap();
    void SiftUp(int childIndex);
    void SiftDown(int siftIndex);

};

template <typename E, typename Comparator>
void HeapSort(QVector<E> unsortedVec, Comparator compare)
{

}

/*************************  IMPLEMENTATION  *********************************/

/*------------------------------------------------------------------------------
  void Insert(const E &newElement);

  Adds a new node with the following steps:
  1. Adds the new element to the end
  2. Increments the end
  3. Fixes the heap
------------------------------------------------------------------------------*/
template <typename E>
void Heap<E>::Insert(const E &newElement)
{
    //1. Adds the new element to the end
    CompleteBinaryTree<E>::tree.push_back(newElement);

    //2. Increments the end
    CompleteBinaryTree<E>::end++;

    //3. Fixes the heap
    FixHeap();

}

/*------------------------------------------------------------------------------
  void FixHeap();

  This method fixes the order of the heap after a new element is added
------------------------------------------------------------------------------*/
template <typename E>
void Heap<E>::FixHeap()
{
    SiftUp(CompleteBinaryTree<E>::end - 1);
}

/*------------------------------------------------------------------------------
  void SiftUp(int nodeIndex);

  This method fixes the order of the heap after a new element is added

  1. Compare current node's value to it's parent
        If they are out of order, swap them
------------------------------------------------------------------------------*/
template <typename E>
void Heap<E>::SiftUp(int childIndex)
{
    E temp;
    int parentIndex = CompleteBinaryTree<E>::Parent(childIndex);

    //Checks if the tree is empty
    if (CompleteBinaryTree<E>::IsEmpty())
    {
        throw Empty();
    }

    if (maxHeap)
    {
        //If they are out of order
        if (CompleteBinaryTree<E>::tree[childIndex] <
            CompleteBinaryTree<E>::tree[parentIndex])
        {
            //Stores the parent in a temp variable
            temp = CompleteBinaryTree<E>::tree[parentIndex];

            //Assigns the current value to the parent location
            CompleteBinaryTree<E>::tree[parentIndex] =
                    CompleteBinaryTree<E>::tree[childIndex];

            //Assigns the previous parent to the current location
            CompleteBinaryTree<E>::tree[childIndex] = temp;

            //Calls the same method on the parent
            SiftUp(parentIndex);
        }
    }
    else
    {
        //If they are out of order
        if (CompleteBinaryTree<E>::tree[childIndex] <
            CompleteBinaryTree<E>::tree[parentIndex])
        {
            //Stores the parent in a temp variable
            temp = CompleteBinaryTree<E>::tree[parentIndex];

            //Assigns the current value to the parent location
            CompleteBinaryTree<E>::tree[parentIndex] =
                    CompleteBinaryTree<E>::tree[childIndex];

            //Assigns the previous parent to the current location
            CompleteBinaryTree<E>::tree[childIndex] = temp;

            //Calls the same method on the parent
            SiftUp(parentIndex);
        }
    }

}

/*------------------------------------------------------------------------------
  void Remove() const;

  Removes the node from the top of the heap

  1. Copies the last value in the array to the root
  2. Deletes the last node in the array
  3. Sifts down the value at the root
------------------------------------------------------------------------------*/
template <typename E>
void Heap<E>::Remove()
{
    if(CompleteBinaryTree<E>::IsEmpty())
    {
        throw Empty();
    }
    else
    {
        //1. Copies the last value in the array to the root
        CompleteBinaryTree<E>::tree[CompleteBinaryTree<E>::root]
                = CompleteBinaryTree<E>::tree[CompleteBinaryTree<E>::end - 1];

        //2. Deletes the last node in the array
        CompleteBinaryTree<E>::tree.pop_back();
        CompleteBinaryTree<E>::end--;

        //3. Sifts down the value at the root
        if(CompleteBinaryTree<E>::GetSize() > 0)
        {
            SiftDown(CompleteBinaryTree<E>::root);
        }
    }
}

/*------------------------------------------------------------------------------
  void SiftDown(int nodeIndex) const;

  Sifts down the node located in the index passed in

  1. If the node has no children, sifting is done
  2. If the node has one child, assign minChild to the left child
  3. If the node has two children, assign minChild to the smallest of them
  4. If the heap propery is broken with the current node and the minChild,
     swap the node with the smallest child and sift down the child
------------------------------------------------------------------------------*/
template <typename E>
void Heap<E>::SiftDown(int siftIndex)
{
    E temp;
    int minChildIndex;
    int rChildIndex = CompleteBinaryTree<E>::RChild(siftIndex);
    int lChildIndex = CompleteBinaryTree<E>::LChild(siftIndex);

    if(rChildIndex >= CompleteBinaryTree<E>::end)
    {
        if(lChildIndex >= CompleteBinaryTree<E>::end)
        {
            //1. If the node has no children, sifting is done
            return;
        }
        else
        {
            //2. If the node has one child, assign minChild to the left child
            minChildIndex = lChildIndex;
        }
    }
    else
    {
        //3. If the node has two children, assign minChild to the smallest of
        //   them
        if(CompleteBinaryTree<E>::tree[lChildIndex] <= CompleteBinaryTree<E>::tree[rChildIndex])
        {
            minChildIndex = lChildIndex;
        }
        else
        {
            minChildIndex = rChildIndex;
        }
    }

    //4. If the heap propery is broken with the current node and the minChild,
    //   swap the node with the smallest child and sift down the child
    if(CompleteBinaryTree<E>::tree[siftIndex] > CompleteBinaryTree<E>::tree[minChildIndex])
    {
        //Stores the parent in a temp variable
        temp = CompleteBinaryTree<E>::tree[siftIndex];

        //Assigns the minChild value to the parent location
        CompleteBinaryTree<E>::tree[siftIndex] =
                CompleteBinaryTree<E>::tree[minChildIndex];

        //Assigns the previous parent to the location of the old minChild
        CompleteBinaryTree<E>::tree[minChildIndex] = temp;

        //Calls the same method on the new child
        SiftDown(minChildIndex);
    }
}

/*------------------------------------------------------------------------------
  string PrintHeap() const;

  POST: Returns a string with the data in the heap represented in order
------------------------------------------------------------------------------*/
template <typename E>
string Heap<E>::PrintHeap()
{
    ostringstream out;

    out << "Teams: [";
    for(int i = CompleteBinaryTree<E>::root; i < CompleteBinaryTree<E>::end; ++i)
    {
        out << CompleteBinaryTree<E>::tree[i].GetTeam();
        if(i + 1 < CompleteBinaryTree<E>::end)
            out << ", ";
    }
    out << "]\n";

    out << "Keys: [";
    for(int i = CompleteBinaryTree<E>::root; i < CompleteBinaryTree<E>::end; ++i)
    {
        out << CompleteBinaryTree<E>::tree[i].GetKey();
        if(i + 1 < CompleteBinaryTree<E>::end)
            out << ", ";
    }
    out << "]\n\n";

    return out.str();

}

/*------------------------------------------------------------------------------
  string GraphTree(string fileName) const;

  POST: Returns a string with the data in the heap represented in order
------------------------------------------------------------------------------*/
template <typename E>
void Heap<E>::GraphTree(string fileName,
                        string graphName) const
{
    ofstream oFile;
    int rChild = CompleteBinaryTree<E>::end;
    int lChild = CompleteBinaryTree<E>::end;

    //Begins the graph & opens the file
    oFile.open(fileName.c_str());
    oFile << "digraph \"" <<  graphName << "\"  " << endl;
    oFile << "{ \n\n";
//		  << "      rankDir = LR;\n"
//		  << "      node [shape = record, width = 0.1, height = 0.1]"
//		  << "      rotate = 90;\n"

    oFile << "\"" << graphName << "\"[label = \"" << graphName << "\"]" << endl;

    //Creates all the nodes
    for(int i = CompleteBinaryTree<E>::root; i < CompleteBinaryTree<E>::end; i++)
    {
        oFile << GraphNode(i);
    }

    //Makes all the arrows
    for(int j = CompleteBinaryTree<E>::root; j < CompleteBinaryTree<E>::end; j++)
    {
        //Sets the right and left children
        rChild = CompleteBinaryTree<E>::RChild(j);
        lChild = CompleteBinaryTree<E>::LChild(j);

        //Outputs the beginning of the arrow:
        // node(i) -> {
        oFile << "node \"" << CompleteBinaryTree<E>::tree[j] << "\" -> { ";

        //If they have a left child, connect it
        if(lChild < CompleteBinaryTree<E>::end)
        {
            oFile << "node \"" << CompleteBinaryTree<E>::tree[lChild] << "\" ";
        }

        //If they have a right child, connect it
        if(rChild < CompleteBinaryTree<E>::end)
        {
            oFile << "node \"" << CompleteBinaryTree<E>::tree[rChild] << "\" ";
        }

        oFile << "};\n";
    }

    //Ends the graph & closes the file
    oFile << endl << "}\n\n";
    oFile.close();
}

//node(i)[label = "(The node)"]
template <typename E>
string Heap<E>::GraphNode(int i) const
{
    ostringstream out;

    out << "node\"" << CompleteBinaryTree<E>::tree[i] << "\" [label = \""
        << CompleteBinaryTree<E>::tree[i] << "\"]\n";

    return out.str();
}

#endif // HEAP

