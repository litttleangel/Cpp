

#include<stdlib.h>
#include"Vector.h"
#include<iostream>
using namespace std;


void TestVector()
{
	/*Vector v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	v1.PushBack(5);
	v1.PushBack(6);
	v1.PushBack(7);
	v1.Show();

	Vector v2(v1);
	v2.Show();

	Vector v3;
	v3= v1;
	v3.PopBack();
	v3.PopBack();
	v3.PopBack();
	v3.PopBack();
	v3.PopBack();
	v3.PopBack();
	v3.PopBack();
	v3.Show();

	v3.PushBack(0);
	v3.Show();
*/


	Vector v5;
	v5.Insert(0, 0);
	v5.Insert(1, 1);
	v5.Insert(2, 2);
	v5.Insert(3, 3);
	v5.Insert(4, 4);
	v5.Insert(5, 5);
	v5.Insert(6, 6);
	v5.Insert(7, 7);
	v5.Show();


	v5.Erase(0);
	v5.Erase(1);
	/*v5.Erase(2);
	v5.Erase(3);
	v5.Erase(4);*/
	v5.Erase(5);

	v5.Erase(6);
	v5.Erase(7);
	v5.Show();

}


int main()
{
	TestVector(); 
	system("pause");
	return 0;
}