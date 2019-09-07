#include<bits/stdc++.h>
using namespace std;

struct TrieNode 
{
    TrieNode* children[26];
    bool is_endofword;
};

TrieNode* create_node()
{
    TrieNode* node = new TrieNode;
    node->is_endofword = false;
    for (int i=0; i<26; i++) node->children[i] = nullptr;
    return node;
}

void insert(TrieNode* root, string word)
{
    TrieNode* cur = root;
    int l = word.length();
    for (int i=0; i<l; i++)
    {
        if (!cur->children[word[i] - 'a'])
        {
            cur->children[word[i] - 'a'] = create_node();
        }
        cur = cur->children[word[i] - 'a'];
    }
    cur->is_endofword = true;
}

bool search_prefix(TrieNode* cur, string word)
{
    int l = word.length();
    for (int i=0; i<l; i++)
    {
        if (!cur->children[word[i] - 'a'])
        {
            return false;        
        }
        cur = cur->children[word[i] - 'a'];
    }
    return true;
}   

bool search_word(TrieNode* cur, string word)
{
    int l = word.length();
    for (int i=0; i<l; i++)
    {
        if (!cur->children[word[i] - 'a'])
        {
            return false;        
        }
        cur = cur->children[word[i] - 'a'];
    }

    return cur->is_endofword;
}

bool is_node_empty(TrieNode* root)
{
    for (int i=0; i<26; i++)
        if(root->children[i]) return false;
    return true;
}

bool delete_word(TrieNode* root, string word, int index)
{
    TrieNode* cur = root;
    if (index == word.length())
    {
        if (cur->is_endofword) 
        {
            cur->is_endofword = false;
            return is_node_empty(cur);
        }
        return false; 
    }
    
    bool to_delete = false;
    if (cur->children[word[index] - 'a']) 
    {
        //cout<<"\nhere"<<word[index]<<endl;
        to_delete = delete_word(cur->children[word[index] - 'a'], word, index + 1);
    }
    //cout<<"\n"<<word[index]<<" to_delete: "<<to_delete<<endl;
    if (to_delete)
    {
        delete(cur->children[word[index] - 'a']);
        cur->children[word[index] - 'a'] = nullptr;
    }
    return is_node_empty(cur);
}

void delete_word(TrieNode* root, string word)
{
    delete_word(root, word, 0);
}

void customized_input()
{
    TrieNode* root = create_node();
    cout<<boolalpha; // To print boolean values as true and false and not 0 and 1
    
    char task = 'x';
    string word;

    cout<<"\ninsert word: i, delete word: d, search word: w, search prefix: p, exit: e.\n"; 
    while(task != 'e')
    {
        cout<<"\ni/d/w/p/e: ";
        cin>>task;
        switch (task) 
        {
            case 'i':   cout<<"Word: "; cin>>word;
                        insert(root, word);
                        break;
            case 'd':   cout<<"Word: "; cin>>word; 
                        delete_word(root, word); 
                        break;
            case 'w':   cout<<"Word: "; cin>>word; 
                        cout<<search_word(root, word)<<"\n"; 
                        break;
            case 'p':   cout<<"Prefix: "; cin>>word; 
                        cout<<search_prefix(root, word)<<"\n";
                        break;
            case 'e':   cout <<"\n"; return; 
                        break;
            default:    cout <<"Unexpected input.\n"; 
                        break;
        }
    }
}

void default_input()
{
    TrieNode* root = create_node();
    cout<<boolalpha; // To print boolean values as true and false and not 0 and 1

    cout<<"\nInserting abc."; insert(root, "abc");
    cout<<"\nInserting abgl."; insert(root, "abgl");
    cout<<"\nInserting cdf."; insert(root, "cdf");
    cout<<"\nInserting abcd."; insert(root, "abcd");
    cout<<"\nInserting lmn."; insert(root, "lmn");

    cout<<"\n\nSearching for word abc: "; cout<<search_word(root, "abc");
    cout<<"\nSearching for word abgl: "; cout<<search_word(root, "abgl");
    cout<<"\nSearching for word ab: "; cout<<search_word(root, "ab");
    cout<<"\nSearching for word efg: "; cout<<search_word(root, "efg");

    cout<<"\n\nSearching for prefix abc: "; cout<<search_prefix(root, "abc");
    cout<<"\nSearching for prefix ab: "; cout<<search_prefix(root, "ab");
    cout<<"\nSearching for prefix e: "; cout<<search_prefix(root, "e");

    cout<<"\n\nDeleting abc."; delete_word(root, "abc");
    cout<<"\nDeleting ab."; delete_word(root, "ab");
    cout<<"\nDeleting efg."; delete_word(root, "efg");

    cout<<"\n\nSearching for prefix abc: "; cout<<search_prefix(root, "abc");
    cout<<"\nSearching for word abc: "; cout<<search_word(root, "abc");
    cout<<"\nSearching for prefix ab: "; cout<<search_prefix(root, "ab");
    cout<<"\nSearching for prefix ef: "; cout<<search_prefix(root, "ef");
    cout<<"\nSearching for prefix l: "; cout<<search_prefix(root, "l");
    
    cout<<"\n";
}

int main()
{
    char input_type;
    cout<<"\nEnter d for default input, c for customized input: ";
    cin>>input_type;

    if (input_type == 'd') 
    {
        default_input();
    }
    else 
    {
        customized_input();
    }
    cout<<"\n";
    return 0;
}
