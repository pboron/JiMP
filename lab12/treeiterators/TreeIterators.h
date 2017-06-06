//
// Created by Rambo on 2017-06-05.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <vector>
#include "../tree/Tree.h"

namespace tree {
    template<class T>
    class GenericIterator {
    public:
        GenericIterator(Node<T> *head_) : head_(head_) {}
        virtual void GenerateVectorOrder(Node<T> *pivot) = 0;
        T operator++() { if (i_ >= 0) ++i_; }
        T operator*() { return generated_[i_]; }
        bool operator!=(const GenericIterator &second) const {
            return generated_ != second.generated_ || i_ != second.i_;
        }

        void setIteration(const size_t &in) { i_ = in; }
        size_t size() const { return generated_.size(); }
        void pushBackValue(const T &val) { generated_.push_back(val); }

    private:
        Node<T> *head_;
        std::vector<T> generated_;
        size_t i_;
    };

    template<class T>
    class PreOrderTreeIterator : public GenericIterator<T> {
    public:
        PreOrderTreeIterator(Node<T> *head_) : GenericIterator<T>(head_) {
            GenerateVectorOrder(head_);
            this->setIteration(0);
        }

        void GenerateVectorOrder(Node<T> *pivot) override {

            this->pushBackValue(pivot->value_);

            if (pivot->left_ != nullptr)
                GenerateVectorOrder(pivot->left_.get());

            if (pivot->right_ != nullptr)
                GenerateVectorOrder(pivot->right_.get());
        }
    };

    template<class T>
    class InOrderTreeIterator : public GenericIterator<T> {
    public:
        InOrderTreeIterator(Node<T> *head_) : GenericIterator<T>(head_) {
            GenerateVectorOrder(head_);
            this->setIteration(0);
        }

        void GenerateVectorOrder(Node<T> *pivot) override {
            if (pivot->left_ != nullptr)
                GenerateVectorOrder(pivot->left_.get());

            this->pushBackValue(pivot->value_);

            if (pivot->right_ != nullptr)
                GenerateVectorOrder(pivot->right_.get());
        }
    };

    template<class T>
    class PostOrderTreeIterator : public GenericIterator<T> {
    public:
        PostOrderTreeIterator(Node<T> *head_) : GenericIterator<T>(head_) {
            GenerateVectorOrder(head_);
            this->setIteration(0);
        }

        void GenerateVectorOrder(Node<T> *pivot) override {

            if (pivot->left_ != nullptr)
                GenerateVectorOrder(pivot->left_.get());

            if (pivot->right_ != nullptr)
                GenerateVectorOrder(pivot->right_.get());

            this->pushBackValue(pivot->value_);
        }
    };

    template<class T>
    class InOrderTreeView {
    public:
        InOrderTreeView(Tree<T> *tree) : iter_(tree->Root()) {}

        InOrderTreeIterator<T> begin() {
            iter_.setIteration(0);
            return iter_;
        }

        InOrderTreeIterator<T> end() {
            iter_.setIteration(iter_.size() - 1);
            return iter_;
        }

    private:
        InOrderTreeIterator<T> iter_;
    };

    template<class T>
    class PreOrderTreeView {
    public:
        PreOrderTreeView(Tree<T> *tree) : iter_(tree->Root()) {}

        PreOrderTreeIterator<T> begin() {
            iter_.setIteration(0);
            return iter_;
        }

        PreOrderTreeIterator<T> end() {
            iter_.setIteration(iter_.size() - 1);
            return iter_;
        }

    private:
        PreOrderTreeIterator<T> iter_;
    };

    template<class T>
    class PostOrderTreeView {
    public:
        PostOrderTreeView(Tree<T> *tree) : iter_(tree->Root()) {}

        PostOrderTreeIterator<T> begin() {
            iter_.setIteration(0);
            return iter_;
        }

        PostOrderTreeIterator<T> end() {
            iter_.setIteration(iter_.size() - 1);
            return iter_;
        }

    private:
        PostOrderTreeIterator<T> iter_;
    };

    template<typename T>
    InOrderTreeView<T> InOrder(Tree<T> *tree) {
        return InOrderTreeView<T>(tree);
    };

    template<typename T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree) {
        return PreOrderTreeView<T>(tree);
    };

    template<typename T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree) {
        return PostOrderTreeView<T>(tree);
    };

}

#endif //JIMP_EXERCISES_TREEITERATORS_H
