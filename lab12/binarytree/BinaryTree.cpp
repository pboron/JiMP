//
// Created by Student on 25.05.2017.
//

#include "BinaryTree.h"
#include <iostream>
#include <sstream>



    std::unique_ptr <SmartTree> CreateLeaf(int value){
        std::unique_ptr <SmartTree> node= std::make_unique<SmartTree>();
        node->value=value;
        return node;
    }
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        if(!tree){
            return nullptr;
        }
        tree->left=std::move(left_subtree);
        return tree;
    }
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right=std::move(right_subtree);
        return tree;
    }
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr->left){
            PrintTreeInOrder(unique_ptr->left,out);
        }

        *out << std::to_string(unique_ptr->value) << ", ";

        if(unique_ptr->right){
            PrintTreeInOrder(unique_ptr->right,out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        if(tree == nullptr){
            return "[none]";
        }
        else{
            return "["+std::to_string(tree->value)+" "+DumpTree(tree->left)+" "+DumpTree(tree->right)+"]";
        }
    }

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){
        const std::string str=tree;
        std::string temp="";
        std::unique_ptr <SmartTree> tree_out;
        int left_cnt=0,right_cnt=0,i=0,k=0;
        do{
            if(str[i]=='['){
                left_cnt++;
                i++;
                if(left_cnt==1){
                    while(str[i]!=32 and str[i]!=']' ){
                        temp+=str[i];
                        i++;
                    }
                    if(temp=="none"){
                        return nullptr;
                    }
                    tree_out=std::move(CreateLeaf(std::stoi(temp)));
                    temp="";

                }
                if(left_cnt==2 and k==0){
                    tree_out->left=std::move(RestoreTree(&(str[i-1])));
                    k=1;
                }
                if(left_cnt==2 and k==1){
                    tree_out->right=std::move(RestoreTree(&(str[i-1])));
                }
            }
            if(str[i]==']'){
                right_cnt++;
                left_cnt--;
            }
            i++;

        }while(left_cnt!=0);
        return tree_out;
    }