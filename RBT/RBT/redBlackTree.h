//Header File Red-Black Tree
 
#ifndef H_redBlackTree
#define H_redBlackTree
#include <iostream>
#include "binaryTree.h" 
 
using namespace std;

template <class elemType>
class rBlackTreeType: public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const;
      //Function to determine if searchItem is in the tree.
      //Postcondition: Returns true if searchItem is found in 
      //               the red-black tree; otherwise, 
      //               returns false.

    void insert(const elemType& insertItem);
      //Function to insert insertItem in the red-black tree.
      //Postcondition: If there is no node in the red-black
      //               tree that has the same info as 
      //               insertItem, a node with the info 
      //               insertItem is created and inserted in the
      //               red-black tree.

    void deleteNode(const elemType& deleteItem);
      //Function to delete deleteItem from the red-black tree 
      //Postcondition: If a node with the same info as deleteItem
      //               is found, it is deleted from the tree.
      //               If the binary tree is empty or deleteItem
      //               is not in the binary tree, an appropriate
      //               message is printed.
	void rotateLeft();

	void rotateRight();
	/*	
	nodeType<elemType>	*pLink;//parrent link
	nodeType<bool>		*color;
	*/


private:
    void deleteFromTree(nodeType<elemType>* &p);
      //Function to delete the node to which p points is 
      //deleted from the red-black tree.
      //Postcondition: The node to which p points is deleted
      //               from the red-black tree.
};

template <class elemType>


template <class elemType>
bool rBlackTreeType<elemType>::search
                    (const elemType& searchItem) const
{
    nodeType<elemType> *current;
    bool found = false;

    if (root == NULL)
        cout << "Cannot search an empty tree." << endl;
    else
    { 
       current = root;

       while (current != NULL && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while
    }//end else

    return found;
}//end search

template <class elemType>
void rBlackTreeType<elemType>::insert
                 (const elemType& insertItem)
{
    nodeType<elemType> *current; //pointer to traverse the tree
    nodeType<elemType> *trailCurrent = nullptr; //pointer behind current
    nodeType<elemType> *newNode;  //pointer to create the node

    newNode = new nodeType<elemType>;
    newNode->info = insertItem;
    newNode->lLink = NULL;
    newNode->rLink = NULL;

    if (root == NULL)
        root = newNode;
    else
    {
        current = root;
 
        while (current != NULL)
        {
            trailCurrent = current;

            if (current->info == insertItem)
            {
                cout << "The item to be inserted is already ";
                cout << "in the tree -- duplicates are not "
                     << "allowed." << endl;
                return;
            }
            else if (current->info > insertItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while

        if (trailCurrent->info > insertItem)
            trailCurrent->lLink = newNode;
        else
            trailCurrent->rLink = newNode;
    }
}//end insert

template <class elemType>
void rBlackTreeType<elemType>::deleteNode
                                (const elemType& deleteItem)
{
    nodeType<elemType> *current; //pointer to traverse the tree
    nodeType<elemType> *trailCurrent; //pointer behind current
    bool found = false;

    if (root == NULL)
        cout << "Cannot delete from an empty tree." 
             << endl;
    else
    {
        current = root;
        trailCurrent = root;

        while (current != NULL && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;

                if (current->info > deleteItem)
                    current = current->lLink;
                else
                    current = current->rLink;
            }
        }//end while

        if (current == NULL)
            cout << "The item to be deleted is not in the tree." 
                 << endl;
        else if (found)
        {
            if (current == root)
                deleteFromTree(root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->lLink);
            else
                deleteFromTree(trailCurrent->rLink);
        }
        else
            cout << "The item to be deleted is not in the tree."
                 << endl;
    }
} //end deleteNode

template <class elemType>
void rBlackTreeType<elemType>::deleteFromTree
                                 (nodeType<elemType>* &p)
{
    nodeType<elemType> *current; //pointer to traverse the tree
    nodeType<elemType> *trailCurrent;  //pointer behind current
    nodeType<elemType> *temp;      //pointer to delete the node

    if (p == NULL)
        cout << "Error: The node to be deleted is NULL."
             << endl;
    else if (p->lLink == NULL && p->rLink == NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if (p->lLink == NULL)
    {
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if (p->rLink == NULL)
    {
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else
    {
        current = p->lLink;
        trailCurrent = NULL;

        while (current->rLink != NULL)
        {
            trailCurrent = current;
            current = current->rLink;
        }//end while

        p->info = current->info;

        if (trailCurrent == NULL) //current did not move; 
                               //current == p->lLink; adjust p
            p->lLink = current->lLink;
        else
            trailCurrent->rLink = current->lLink;
 
        delete current;
    }//end else
} //end deleteFromTree

#endif
