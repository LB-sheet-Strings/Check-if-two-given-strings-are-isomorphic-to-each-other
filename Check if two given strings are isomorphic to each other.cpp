/*
A Simple Solution is to consider every character of ‘str1’ and check if all occurrences of it map to same character in ‘str2’. 
Time complexity of this solution is O(n*n).

My approach: Use map

Functions to be used:
end():  Returns an iterator pointing to the position past the last element in the container in the unordered_map containe
find(): returns an iterator or a constant iterator that refers to the position where the key is present in the map. 
        If the key is not present in the map container, it returns an iterator or a constant iterator which refers to map.end().
//at() sidha key ki value return karta hai

TC=O(n)
SC=O(n)

without map

 bool areIsomorphic(string str1, string str2)
    {
        
        int m = str1.length(), n = str2.length();
 
    // Length of both strings must be same for one to one
    // corresponance
    if (m != n)
      return false;
 
    // To mark visited characters in str2
    bool marked[MAX_CHARS] = {false};
 
    // To store mapping of every character from str1 to
    // that of str2. Initialize all entries of map as -1.
    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));
 
    // Process all characters one by on
    for (int i = 0; i < n; i++)
    {
        // If current character of str1 is seen first
        // time in it.
        if (map[str1[i]] == -1)
        {
            // If current character of str2 is already
            // seen, one to one mapping not possible
            if (marked[str2[i]] == true)
                return false;
 
            // Mark current character of str2 as visited
            marked[str2[i]] = true;
 
            // Store mapping of current characters
            map[str1[i]] = str2[i];
        }
 
        // If this is not first appearance of current
        // character in str1, then check if previous
        // appearance mapped to same character of str2
        else if (map[str1[i]] != str2[i])
            return false;
    }
 
    return true;
    }

*/
#include<bits/stdc++.h>  //OPTIONAL
#include<iostream>
#include<cstring>
#include <unordered_map>

using namespace std;

void areIsomorphic(string str1,string str2,int l1)  //dono ka length same hai to l1 daalo ya l2
{
	int key,value,flag=0;
	
	//map bnao har character ka such that key==str1[i] and value=str2[i]
	 unordered_map<int,int> m;
 
    //chalte chalte values insert karo map me
    for(int i=0;i<l1;i++)
    {
    	key=(int)str1[i];
    	value=(int)str2[i];
    	
    	// if map is empty or Key is not present, insert key and the value
    	if (m.find(key)==m.end())
    	{
    		//pair(mapping) bnaye
    		m.insert(make_pair(key,value));
		}
		// Key is already present to dekho ki kya uski value str2[i] (current element) ke barabar hai kya
		else if(m.find(key)!=m.end())
		{
			//agar hai to aage badho(maine ye include nhi kiya yaha bcoz understood hai)  
			//agar nhi hai to false print karo kyuki 1 to 1 mapping honi chaiye,
			//ek hi element ki 2 mapping nhi honi chaiye
			if(m.at(key)!=value)
			{
				cout<<"\n\nNOT ISOMORPHIC!!";
				flag=1;
			}
		}
	}
	
	if(flag==0)
	{
		cout<<"\n\nISOMORPHIC!!";
	}
    
}

int main()
{
	string str1,str2;
	
	cout<<"\nString 1 => ";
	cin>>str1;
	
	cout<<"\nString 2 => ";
	cin>>str2;
	
	int l1=str1.length();
	int l2=str2.length();
	
	//corner case
	if(l1!=l2)
	{
		cout<<"\nLengths must be same!!";
	}
	else if(l1==l2)
	{
		//call our function
		areIsomorphic(str1,str2,l1);
	}
	
	return 0;
}
