#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {

}
void destroyNode(MovieNode *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
 }

MovieTree::~MovieTree() {
  destroyNode(root);
}

MovieNode* createNode(int ranking, string title, int year, float rating)
{
  MovieNode* newNode = new MovieNode(ranking, title, year, rating);
  newNode->ranking = ranking;
  newNode ->title = title;
  newNode -> year = year;
  newNode->rating = rating;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

MovieNode* addNodeHelper(MovieNode* currNode, int ranking, string title, int year, float rating)
{
  if(currNode == NULL){
   return createNode(ranking, title, year, rating);
  }
  if (title >= currNode -> title){
    currNode->right = addNodeHelper(currNode->right, ranking, title, year, rating);
  }
  else if (title < currNode->title){
    currNode->left = addNodeHelper(currNode->left, ranking, title, year, rating); 
  }
  return currNode;
}

void MovieTree::addMovieNode(int ranking, std::string title, int year, float rating)
{
  root = addNodeHelper(root, ranking, title, year, rating);
}

void printTreeHelper(MovieNode* currNode){  
  if (currNode) {
    printTreeHelper( currNode->left);
    cout << "Movie: "<< currNode->title << " " << currNode->rating<< endl;
    printTreeHelper( currNode->right);
  }
}

void MovieTree::printMovieInventory()
{
  if (root == NULL) {
    cout << "Tree is Empty. Cannot print" << endl;
  }
  else {
    printTreeHelper(root);
  }
}

MovieNode* searchKeyHelper(MovieNode* currNode, string data){
  if(currNode == NULL){
    return NULL;
  }
  if(currNode->title == data){
    return currNode;
  }
  if(currNode->title > data){
    return searchKeyHelper(currNode->left, data);
  }
  return searchKeyHelper (currNode->right, data);
}

void MovieTree::findMovie(string title) {
  MovieNode* tree = searchKeyHelper(root, title);
  if(tree != NULL) {
    cout <<"Movie Info:"<< endl;
    cout <<"=================="<< endl;
    cout <<"Ranking:"<< tree->ranking << endl;
    cout <<"Title  :"<< tree->title << endl;
    cout <<"Year   :"<< tree->year << endl;
    cout <<"rating :"<< tree->rating << endl;
  }
  else {
    cout<<"Movie not found."<<endl;
  }
}

void selectiveTreeHelper(MovieNode* currNode, float rating, int year){ 
  if (currNode) {
     if ((currNode->rating>= rating) && (currNode->year>year)){
        cout << currNode->title << "(" << currNode->year << ") " << currNode->rating<< endl;
    }
    selectiveTreeHelper( currNode->left, rating,year);
    selectiveTreeHelper( currNode->right,rating,year);
  }
}

void MovieTree::queryMovies(float rating, int year) {
  if (root == NULL) {
    cout << "Tree is Empty. Cannot query Movies" << endl;
  }
  else {
    cout << "Movies that came out after " << year << " with rating at least " << rating<< ":"<< endl;
    selectiveTreeHelper(root, rating, year);
  }
}

double addTreeHelper(MovieNode* currNode, double& returnVal){ // totaling all the ratings
  if (currNode) {
    addTreeHelper( currNode->left, returnVal);
    returnVal = currNode ->rating + addTreeHelper( currNode->right, returnVal);
  }
  return returnVal;
 }
 
 double countTreeHelper(MovieNode* currNode, double& total){ //counts how many nodes there are
  if (currNode) {
    countTreeHelper(currNode->left, total);
    total++;
    countTreeHelper(currNode->right, total);
  }
  return total;
 }
 
void MovieTree::averageRating() {
  double totalRatings = 0;
  double totalNodes = 0;
  if (root == NULL) {
    cout << "Average rating:0.0" << endl;
    }
  else {
  double average = addTreeHelper(root, totalRatings);
  average =  average / countTreeHelper(root, totalNodes);
  cout<< "Average rating:" << average << endl;
  }
}

int totalHeight(MovieNode* currNode){
    if (currNode == NULL){
        return 0;
    }
    else {
        int leftTree = totalHeight(currNode ->left);
        int rightTree = totalHeight(currNode->right);
        
        if (leftTree>rightTree){ //pick largest height
            return (leftTree+1);
        }
        else{
            return (rightTree+1);
        }
    }
}

// referenced https://www.techiedelight.com/level-order-traversal-binary-tree/

void printDistance(MovieNode *currNode , int n) {
  if (currNode == NULL){
    return;
  } 
  if(n == 0) { //looking at root AND base case  
    cout << "Movie: " << currNode->title << " " << currNode->rating<< endl;  
    return;  
  }  
  else {  
    printDistance(currNode->left, n - 1);  
    printDistance(currNode->right, n - 1 );  
  }
  }

void MovieTree::printLevelNodes(int level) {
    if (totalHeight(root)>level){
        printDistance(root, level);
    }
}