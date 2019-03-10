
#include <bits/stdc++.h> 


  


using namespace std; 


  


//each element in the trie tree 


struct node 


{ 


    bool end_string; 


    struct node *next_char[26]; 


}; 


  


//to insert the string in the trie tree 


void insert(struct node *head, string str) 


{ 


    int i, j; 


    for(i = 0;i < str.size(); ++i){ 


        //if the child node is pointing to NULL 


        if(head -> next_char[str[i] - 'a'] == NULL){ 


            struct node *n; 


            //initialise the new node 


            n = new struct node; 


            for(j = 0;j < 26; ++j){ 


                n -> next_char[j] = NULL; 


            } 


            n -> end_string = 0; 


            head -> next_char[str[i] - 'a'] = n; 


            head = n; 


        } 


        //if the child node is not pointing to q 


        else head = head -> next_char[str[i] - 'a']; 


    } 


     //to mark the end_string flag for this string 


    head -> end_string = 1; 


} 


  


// to check is the string lies in trie tree 


bool check(struct node *head, string str) 


{ 


    int i; 


    for(i = 0;i < str.size(); ++i){ 


        if(head -> next_char[str[i] - 'a'] == NULL) return false; 


        else head = head -> next_char[str[i] - 'a']; 


    } 


    //check if the end_string flag is 1 


    if(head -> end_string == 1) return true; 


    else return false; 


} 


  


int main() 


{ 


    int n, m, i; 


    //n = number of string's to be inserted in trie tree 


    //m = number of string's to be checked in trie tree 


  


    struct node *head; 


    head = new struct node; 


  


    //initialise the new node 


    for(i = 0;i < 26; ++i){ 


            head -> next_char[i] = NULL; 


    } 


    head -> end_string = 0; 


  


    cin >> n; 


    while(n--){ 


        string str; 


        cin >> str; 


        insert(head, str); //to insert the string in the trie tree 


    } 


  


    cin >> m; //number of string's to be checked 


    while(m--){ 


        string str; 


        cin >> str; 


        if(check(head, str)) cout << "present\n"; 


        else cout << "not present\n"; 


    } 


    return 0; 


} 

