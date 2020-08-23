#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>

using namespace std;

struct Trie
{
	Trie * next[26];
	map<int,int> m;
	
	Trie(){
		memset(next,0,sizeof(next));
	}	
	~Trie(){
		for(int i=0 ; i<26; i++)
			if(next[i])
				delete next[i];
	}
};

struct Trie * forward_root;
struct Trie * reverse_root;

void reverse_insert(string str)
{
	struct Trie * cur = reverse_root;
	
	for(int i=str.length()-1 ; i>=0 ; i--)
	{
		if(cur->next[str[i]-'a'] == 0)
		{
			cur->next[str[i]-'a'] = new Trie();
			cur = cur->next[str[i]-'a'];
			cur->m[str.length()]=1;
		}
		else
		{
			cur = cur->next[str[i]-'a'];
			cur->m[str.length()]+=1;
		}
	}
}

void insert(string str)
{
	struct Trie * cur = forward_root;
	
	for(char ch:str)
	{
		if(cur->next[ch-'a'] == 0)
		{
			cur->next[ch-'a'] = new Trie();
			cur = cur->next[ch-'a'];
			cur->m[str.length()]=1;
		}
		else
		{
			cur = cur->next[ch-'a'];
			cur->m[str.length()]+=1;
		}
	}
}

int forward_find(string str, int str_len)
{
	struct Trie * cur = forward_root;	
	
	for(char ch:str)
	{
		if(cur->next[ch-'a']==0)
			return 0;
		else
			cur = cur->next[ch-'a'];
	}
	
	return cur->m[str_len];
}

int reverse_find(string str, int str_len)
{
	struct Trie * cur = reverse_root;	
	
	for(char ch:str)
	{
		if(cur->next[ch-'a']==0)
			return 0;
		else
			cur = cur->next[ch-'a'];
	}
	
	return cur->m[str_len];
}

int main(){
	vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?", "?????"};
    vector<int> answer;
    
    forward_root = new Trie();
    reverse_root = new Trie();
    
    for(int i=0 ; i<words.size() ; i++)
    {
		reverse_insert(words[i]);
    	insert(words[i]);
	}
	
    for(int i=0 ; i<queries.size() ; i++)
    {
    	int start_idx = queries[i].find('?');
    	
    	if(start_idx != 0)
    	{
    		string temp_str="";
    		
    		for(int j=0; j<start_idx ; j++)
    			temp_str+=queries[i][j];
			
			answer.push_back(forward_find(temp_str,queries[i].length()));
		}
		else
		{
			int end_idx = queries[i].rfind('?');
			
			if(end_idx < queries[i].length()-1)
			{
				string temp_str = "";
				
				for(int j=queries[i].length()-1 ; j>end_idx ; j--)
					temp_str+=queries[i][j];
				
				answer.push_back(reverse_find(temp_str,queries[i].length()));
			}
			else
			{
				int sum=0;
				
				for(int j=0 ; j<26 ; j++)
				{
					if(forward_root->next[j] == 0)
						continue;
						
					struct Trie * cur = forward_root->next[j];
					
					sum+=cur->m[queries[i].length()];
				}
				answer.push_back(sum);
			}
		}
	}
	
	for(int i=0 ; i<answer.size() ; i++)
		cout<<answer[i]<<" ";
}
