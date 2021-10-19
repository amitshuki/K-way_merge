
#pragma once
#include <iostream>

	class TreeNode
	{
	private:
		long data;
		int index;



	public:
		//ctor and dtor
		TreeNode();
		TreeNode(long data, int _index);
	
		//~TreeNode() {
	
		

		//getters
	
		int getdata() { return data; }
		


		//setters
		
		void setIndex(int index) { index = index; }
		void SetNum(long num) { data = num; }
	
		int getIndex() { return index; }
		TreeNode& operator=(const TreeNode& other)
		{
			this->data = other.data;
			this->index = other.index;
		;

			return (*this);
		}

		//friends
	
		friend class Heap;



	};



