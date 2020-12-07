#include <iostream>
#include <sstream>
using namespace std;

// implement as an STL version set
class binarySearchTree
{
	public:
        binarySearchTree( );
        binarySearchTree( const binarySearchTree &t );
        ~binarySearchTree( );

        int findMin( );
        int findMax( );
        bool contains( int x );
        bool isEmpty( ) const;
        void print( ostream &out );

        void makeEmpty( );
        void insert( int x );
        void remove( int x );

        const binarySearchTree &operator=( const binarySearchTree &rhs );

        // to complete with AVL
        int upperBound( int keyBound ); // returns the smallest key in the tree such that key > x ( log n )
        int lowerBound( int keyBound ); // returns the smallest key that could also be equal ( log n )
        int keybyorder( int i ); // return the ith largest key ( log n )
        int orderofkey( int key ); // returns the number of keys less than the key param ( log n )
        
	private:
        struct node
        {
            int element;
            node *left;
            node *right;
            int height;
        };
        node *root;

        void insert( int x, node *&t );
        void remove( int x, node *&t );

        // internal method
        node *findMin( node *t )
        {
            if( t == nullptr )
                return nullptr;
            else if( t->left == nullptr )
                return t;
            return findMin( t->left );
        }

        node *findMax( node *t )
        {
            if( t == nullptr )
                return nullptr;
            else if( t->right == nullptr )
                return t;
            return findMax( t->right );
        }

        bool contains( int x, node *t );
        void makeEmpty( node *&t );
        void print( node *&t, ostream &out, string seperator = ", " );

        // internal method of copying the tree
        node *clone( node *t ) 
        {
            if( t == nullptr )
                return nullptr;

            node *temp = new ( nothrow ) node;
            if( temp == nullptr )
                return nullptr;
            temp->element = t->element;
            temp->left = clone( t->left );
            temp->right = clone( t->right );
            return temp;
        }
};