//
// Created by Student on 25.05.2017.
//

#ifndef JIMP_EXERCISES_BINARYTREE_H
#define JIMP_EXERCISES_BINARYTREE_H

#include <ostream>
#include <string>
#include <memory>


    class SmartTree{
    public:
        int value;
        std::unique_ptr<SmartTree> left,right;
    };

    std::unique_ptr <SmartTree> CreateLeaf(int value);
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree);
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree);
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out);
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);

    class Leaf{

    };

    class BinaryTree{

    };

#endif //JIMP_EXERCISES_BINARYTREE_H