https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

struct Node
{
    Node* links[26];
    bool flag=false;

    bool ContainsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a']=node;
    }

    void setEnd(){
        flag=true;
    }

    bool Check_End(){
        return flag;
    }
};

class Trie
{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string word)
    {
        Node* node;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->ContainsKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool check(string word)
    {
        Node* node=root;
        for(int i=0; i<word.size(); i++)
        {
            if(node->ContainsKey(word[i]))
            {
                node=node->get(word[i]);
                if(!node->Check_End())
                    return false;
            }
            else
                return false;
        }
        return true;
    }
}

string complete_string(int n, vector<string>&a)
{
    Trie trie;
    for(int i=0; i<a.size(); i++)
    {
        trie.insert(a[i]);
    }
    string longest="";

    for(int i=0; i<a.size(); i++)
    {
        if(check(a[i]))
        {
            if(a.size()>longest.size())
                longest=a;
            else if(a.size()==longest.size() and a<longest)
                longest=a;
        }
    }
    if(longest=="")
        return "none";
    else
        return longest;
}
