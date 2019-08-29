#include<iostream>
#include<vector>
#include"test.h"
using namespace std;

int main()
{
    vector<vector<float>> vec2;
    vec2=vector<vector<float>>(2,vector<float>(3,0));
    mat_print(vec2);
    float blurring=0.12;
    float center_prob=1-blurring;
	float corner_prob=blurring/12.0;
	float adjacent_prob=blurring/6.0;

	vector<vector<float>> window=
	{
		{corner_prob,adjacent_prob,corner_prob},
		{adjacent_prob,center_prob,adjacent_prob},
		{corner_prob,adjacent_prob,corner_prob}
	};
    mat_print(window);
    return 0;
}