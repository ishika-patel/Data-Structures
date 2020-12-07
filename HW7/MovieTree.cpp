#include <iostream>
#include <fstream>
#include <string>
#include "MovieTree.hpp"

using namespace std;

/* -------------------------------------------------------------------------------------------------------- */
MovieTree::MovieTree()
{
	root = NULL;
}

/* -------------------------------------------------------------------------------------------------------- */

void destroyNode(TreeNode *currNode)
{
   
   if(currNode == NULL){
         return;
    }
    else
    {
        destroyNode(currNode->leftChild);
        destroyNode(currNode->rightChild);

        LLMovieNode *ptr = currNode->head;

        while (ptr != NULL)
        {
            LLMovieNode *temp = ptr->next;
            delete ptr;
            ptr = temp;
        }
        delete currNode;
    }
}

MovieTree::~MovieTree()
{
    destroyNode(root);
    //root = NULL;
}

/* -----------------------------------PRINT MOVIE INVENTORY--------------------------------------------------------------------- */

void printLL(TreeNode* currNode)
{
    while (currNode->head!= NULL)
    {
        cout << " >> " << currNode->head->title << " " << currNode->head->rating << endl;
        currNode->head = currNode->head->next;
    }
}

void printTreeHelper(TreeNode* currNode){
    
    if (currNode)
    {
        printTreeHelper(currNode->leftChild);
        cout << "Movies starting with letter: " << currNode->titleChar << endl;
        printLL(currNode);
        printTreeHelper(currNode->rightChild);

    }
}
void MovieTree::printMovieInventory()
{
    if (root == NULL)
    {
        cout << "" << endl;
    }
    else
    {
        printTreeHelper(root);
    }
}

/* ----------------------------------ADD MOVIE---------------------------------------------------------------------- */

TreeNode* addNodeHelper(TreeNode* currNode, int ranking, string title, int year, float rating)
{
    if(currNode == NULL)
    { // no tree exists
        LLMovieNode * newMovie = new LLMovieNode(ranking, title, year,rating);
        newMovie->next = NULL;
        TreeNode* newNode = new TreeNode();
        newNode->titleChar = title[0];
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->parent = NULL;
        newNode->head = newMovie;
        return newNode;
    }
    
    if (title[0] > currNode -> titleChar)
    {
        currNode->rightChild = addNodeHelper(currNode->rightChild, ranking, title, year, rating);
        currNode->rightChild->parent = currNode;
    }

    else if (title[0] < currNode->titleChar)
    {
        currNode->leftChild = addNodeHelper(currNode->leftChild, ranking, title, year, rating); 
        currNode->leftChild->parent = currNode;
    }

    else 
    {
        //currNode->leftChild = addNodeHelper(currNode->leftChild, ranking, title, year, rating);
        if (title[0] == currNode->titleChar)
        {
            LLMovieNode* movie = new LLMovieNode(ranking, title, year, rating);
            
            if (title < currNode->head->title || (currNode->head->title).compare(title)>0) // tree node exists but there are no movies
            {
                movie->next = currNode->head;
                currNode->head = movie;
            }
        
            else
            {
                LLMovieNode * crawler = currNode->head;
                bool check = false;
                while(crawler->next != NULL & check == false)
                {
                    if((crawler->next->title).compare(title) > 0){
                        movie ->next = crawler ->next;
                        crawler->next = movie;
                        check = true;
                    }
                    crawler = crawler->next;
                }
                if (check == false) {
                    crawler->next = movie;
                    movie->next = NULL;
                }
            }
        }
       // currNode->rightChild = addNodeHelper(currNode->rightChild, ranking, title, year, rating);
    }
    return currNode;
}

void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
       root = addNodeHelper(root, ranking, title, year, rating);
       
       // this should be the only thing move all to addNodeHelper
       // if title char is less than, is title char is greater than 
    
}  

/* -----------------------------------------------DELETE MOVIE--------------------------------------------------------- */

TreeNode* deleteHelper(TreeNode* tree, string title){
    if (tree == NULL)
    {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return NULL;
    }
    else if(title[0]> tree->titleChar)
    {
        tree->rightChild = deleteHelper(tree->rightChild,title);
    }
    else if(title[0]< tree->titleChar)
    {
        tree->leftChild = deleteHelper(tree->leftChild, title);
    }
    else
    {
        LLMovieNode* temp = tree -> head;
        LLMovieNode* left = NULL;
        bool isFound = false;
        TreeNode* treeMin = tree->rightChild;

        while (temp != 0 && isFound !=true)
        {
            if(temp->title == title)
            {
                isFound = true;
            }
            else 
            {
                left = temp;
                temp = temp->next;
            }
        }

        if(temp == NULL)
        {
            cout << "Movie: " << title << " not found, cannot delete." << endl;
            return NULL;
        }
        else if(left == NULL && temp->next != NULL)
        {
            tree->head = temp->next;
            delete temp;
            delete left;
            return tree;
        }
        else if(left != NULL && temp->next == NULL)
        {
            left->next = NULL;
            delete temp;
            return tree;
        }
        else if(left != NULL && temp->next != NULL)
        {
            left->next = temp->next;
            delete temp;
            return tree;
        }

        if(tree->leftChild == NULL && tree->rightChild == NULL) // no children
        {
            delete tree;
            return NULL;
        }
        else if(tree->leftChild != NULL && tree->rightChild == NULL) //left child
        {
            TreeNode* deleteNode = tree;
            tree->leftChild->parent = tree->parent;
            tree = tree->leftChild;
            delete deleteNode;
        }
        else if(tree->leftChild == NULL && tree->rightChild != NULL) // right child
        {
            TreeNode* deleteNode = tree;
            tree->rightChild->parent = tree->parent;
            tree = tree->rightChild;
            delete deleteNode;
        }
        else //both children
        {
            while(treeMin->leftChild !=NULL){
                treeMin = treeMin->leftChild;
            }
            tree->head = treeMin->head;
            tree->titleChar = treeMin->titleChar;
            tree->rightChild = deleteHelper(tree->rightChild,treeMin->head->title);
        }
    }
    return tree;
}

void MovieTree::deleteMovie(std::string title)
{
    root = deleteHelper(root, title);
}

/* -------------------------------------------------LEFT ROTATE------------------------------------------------------- */

// page 343 visualising data structures book!

void MovieTree::leftRotation(TreeNode* currNode)
{
    TreeNode* RotateNode = currNode->rightChild; // rotation partner to x (aka y) is always the right child

    if (currNode->rightChild == NULL)
    {
        //edge: if ​x ​does not have a right child, don’t perform any rotation.
        return;
    }
    else if (currNode == root)
    {
        //edge: if ​x was the root before rotation, make ​y the new root.
        root = RotateNode;
    }
    else if(currNode->parent->rightChild == currNode) //if x is the right child of parent make y right child of parent in rotation
    {
        currNode->parent->rightChild = RotateNode;
    }
    else ///if x is the left child of parent make y left child of parent in rotation
    {
        currNode->parent->leftChild = RotateNode;
    }

    if(RotateNode->leftChild != NULL)
    {
        RotateNode->leftChild->parent = currNode;
    }
    
    currNode->rightChild = RotateNode->leftChild;
    RotateNode->leftChild = currNode; // x and it’s left descendants become the left subtree of ​y,​ with ​x ​as the left child.
    RotateNode->parent = currNode->parent; // move y into x's position
    currNode->parent = RotateNode; // y becomes parent of x
}

/* -------------------------------------------------------------------------------------------------------- */

//------ Given Methods--------//
void _grader_inorderTraversal(TreeNode * root)
{
	if (root == NULL) {
		return;
	}

	_grader_inorderTraversal(root->leftChild);
	cout << root->titleChar << " ";
	_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}

TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchChar(char key)
{
    return searchCharHelper(root, key);
}
