#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class TreeNode {
public:
	T data;
	TreeNode<T>* left{ nullptr };
	TreeNode<T>* right{ nullptr };
	TreeNode(T d): data(d){}
};

template <typename T>
class BinarySearchTree {
private:
	TreeNode<T>* root{ nullptr };
	int size{ 0 };
public:
	
	//Default constructor for now

	//Methods
	// FOR TESTING
	TreeNode<T>* getRoot() {
		return root;
	}
// ----------------  INSERT  ----------------
	void insertHelper(T val, TreeNode<T>* n){
		if (val == n->data) {
			//shouldnt happen
			return;
		}
		else if (val < n->data) {
			if (n->left == nullptr) {
				TreeNode<T>* newNode{ new TreeNode<T>{val} };
				n->left = newNode;
				size++;
				return;
			}
			return insertHelper(val, n->left);
		}
		else {
			if (n->right == nullptr) {
				TreeNode<T>* newNode{ new TreeNode<T>{val} };
				n->right = newNode;
				size++;
				return;
			}
			return insertHelper(val, n->right);
		}


	}
	void insert(T val) {
		if (root == nullptr) {
			TreeNode<T>* newNode{ new TreeNode<T>{val} };
			root = newNode;
		}
		else {
			insertHelper(val, root);
		}
		size++;

	}
// ------------ LOOKUP -----------------
	bool lookuphelper(T val, TreeNode<T>*n) {
		if (val == n->data) {
			return true;
		}
		else if (val < n->data) {
			if (n->left == nullptr) {
				return false;
			}
			else {
				return lookuphelper(val, n->left);
			}
		}
		else { // val is larger
				if (n->right == nullptr) {
					return false;
				}
				else {
					return lookuphelper(val, n->right);
				}
		}
	}
	bool lookup(T val) {
		if (root == nullptr) {
			return false;
		}
		else {
			return lookuphelper(val, root);
		}
	}
	// ------------ REMOVE ---------
	TreeNode<T>* removeFinder(TreeNode<T>* node , T val) {
		if (val < node->data) {
			if (node->left == nullptr) {
				cout << "val could not be found" << endl;
				return nullptr;
			}
			else if (node->left->data == val) {
				return node;
			}
			return removeFinder(node->left, val);
		}
		else {
			if (node->right == nullptr) {
				cout << "val could not be found" << endl;
				return nullptr;
			}
			else if (node->right->data == val) {
				return node;
			}
			return removeFinder(node->right, val);
		}

	}
	TreeNode<T>* closestFinder(TreeNode<T>* node, T val, bool left) {
			if (left) {
				if (node->left->left == nullptr && node->left->right == nullptr) {
					return node->left;
				}
				else if (node->left->right == nullptr) {
					return node->left;
				}
				else {
					closestFinder(node->left, val, false);
				}
			}
			else {
				if (node->right->left == nullptr && node->right->right == nullptr) {
					return node->right;
				}
				else if (node->right->left == nullptr) {
					return node->right;
				}
				else {
					closestFinder(node->right, val, true);
				}
			}
	}

	/*
	case 2
	BEFORE REMOVAL OF 80

					50
				/		\
			45				70
			/	\			/	\
		20		47		60		80
									\
									100
	
	AFTER
					50
				/		\
			45				70
			/	\			/	\
		20		47		60		100
	*/

	/*
	case 3
	BEFORE REMOVAL OF 70
					50
				/		\
			45				70
			/	\			/	\
		20		47		60		100
	AFTER if left
					50
				/		\
			45				60
			/  \				\
		20		47				100
	AFTER if right
					50
				/		\
			45				100
			/  \			/
		20		47		60
	*/


	void remove(T val) {
		if (root == nullptr) {
			return;
		}
		TreeNode<T>* todelpar = removeFinder(root, val);
		// if root is val to be removed
		if (val == root->data) {
			// TODO
			cout << "todel is parent" << endl;
			TreeNode<T>* tempnode = new TreeNode<T>{ val + 10 };
			tempnode->right = root;
			todelpar = tempnode;
			//case 1
			if (todelpar->right->left == nullptr && todelpar->right->right == nullptr) {
				cout << "case 1" << endl;
				todelpar->right = nullptr;
				cout << "deleted with no reconstructon" << endl;
			}
			// case 2
			else if (todelpar->right->left == nullptr || todelpar->right->right == nullptr) {
				cout << "case 2" << endl;
				if (todelpar->right->left == nullptr) {
					cout << "left left" << endl;
					todelpar->left = todelpar->right->right;
				}
				else {
					cout << "left right" << endl;
					todelpar->right = todelpar->right->left;
				}
			}
			// case 3
			else {
				cout << "case 3" << endl;
				bool anwsered{ false };
				string anwser;
				T replacement;
				// choosing closest left or right
				while (anwsered == false) {
					cout << "left or right: ";
					cin >> anwser;
					if (anwser == "left") {
						anwsered = true;
						replacement = closestFinder(todelpar, val, true)->data;

					}
					else if (anwser == "right") {
						anwsered = true;
						replacement = closestFinder(todelpar, val, false)->data;
					}
				}
				this->remove(replacement);
				todelpar->right->data = replacement;

			}
		}
		// if it is on the right side of parent
		else if (todelpar->right->data == val) {
			cout << "todel on right" << endl;
			//case 1
			if (todelpar->right->left == nullptr && todelpar->right->right == nullptr) {
				cout << "case 1" << endl;
				todelpar->right = nullptr;
				cout << "deleted with no reconstructon" << endl;
			}
			// case 2
			else if (todelpar->right->left == nullptr || todelpar->right->right == nullptr) {
				cout << "case 2" << endl;
				if (todelpar->right->left == nullptr) {
					cout << "right right" << endl;
					todelpar->right = todelpar->right->right;
				}
				else {
					cout << "right left" << endl;
					todelpar->right = todelpar->right->left;
				}
			}
			// case 3
			else {
				cout << "case 3" << endl;
				bool anwsered{ false };
				string anwser;
				T replacement;
				// choosing closest left or right
				while (anwsered == false) {
					cout << "left or right: ";
					cin >> anwser;
					if (anwser == "left") {
						anwsered = true;
						replacement = closestFinder(todelpar->right, val, true)->data;

					}
					else if (anwser == "right") {
						anwsered = true;
						replacement = closestFinder(todelpar->right, val, false)->data;
					}
				}
				this->remove(replacement);
				todelpar->right->data = replacement;

			}
		}
		// if val is left child of todel
		else {
			cout << "todel on left" << endl;
			//case 1
			if (todelpar->left->left == nullptr && todelpar->left->right == nullptr) {
				cout << "case 1" << endl;
				todelpar->left = nullptr;
				cout << "deleted with no reconstructon" << endl;
			}
			// case 2
			else if (todelpar->left->left == nullptr || todelpar->left->right == nullptr) {
				cout << "case 2" << endl;
				if (todelpar->left->left == nullptr) {
					cout << "left right" << endl;
					todelpar->left = todelpar->left->right;
				}
				else {
					cout << "left left" << endl;
					todelpar->left = todelpar->left->left;
				}
			}
			// case 3
			else {
				cout << "case 3" << endl;
				bool anwsered{ false };
				string anwser;
				T replacement;
				// choosing closest left or right
				while (anwsered == false) {
					cout << "left or right: ";
					cin >> anwser;
					if (anwser == "left") {
						anwsered = true;
						replacement = closestFinder(todelpar->left, val, true)->data;

					}
					else if (anwser == "right") {
						anwsered = true;
						replacement = closestFinder(todelpar->left, val, false)->data;
					}
				}
				this->remove(replacement);
				todelpar->left->data = replacement;

			}

		}
	}

		// ----------------------  PRINT  --------------------------------
		void printHelper(TreeNode<T>*node) {
			if (node->left != nullptr) {
				printHelper(node->left);
			}
			cout << " " << node->data << " ";
			if (node->right != nullptr) {
				printHelper(node->right);
			}
		}
		void print() {
			if (root == nullptr) {
				return;
			}
			else {
				printHelper(root);
				cout << endl;
			}
		}
		void preprintHelper(TreeNode<T>*node) {
			cout << " " << node->data << " ";
			if (node->left != nullptr) {
				printHelper(node->left);
			}
			if (node->right != nullptr) {
				printHelper(node->right);
			}
		}
		void preprint() {
			if (root == nullptr) {
				return;
			}
			else {
				preprintHelper(root);
				cout << endl;
			}
		}
};