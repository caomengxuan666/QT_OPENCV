//
// Created by Lenovo on 2024/8/12.
//

#ifndef CMX_IMGSTACK_HPP
#define CMX_IMGSTACK_HPP

#include <opencv2/core.hpp>
#include <stack>

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
public:
    virtual void attach(Observer *observer) = 0;
    virtual void detach(Observer *observer) = 0;
    virtual void notify() = 0;
};

class ImgStack : public Subject {
public:
    ImgStack() = default;
    ~ImgStack() {
        for (auto &obs: observers)
            delete obs;

        while (!UndoImgStack.empty())
            UndoImgStack.pop();

        while (!RedoImgStack.empty())
            RedoImgStack.pop();
    }


    void addToStack(const cv::Mat &img) {
        UndoImgStack.push(img);
        RedoImgStack = std::stack<cv::Mat>();// 清空重做栈
        notify();
    }

    void attach(Observer *observer) override {
        observers.push_back(observer);
    }

    void detach(Observer *observer) override {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end())
            observers.erase(it);
    }


    void undo() {
        if (!UndoImgStack.empty()) {
            RedoImgStack.push(UndoImgStack.top());
            UndoImgStack.pop();
            notify();
        }
    }

    void redo() {
        if (!RedoImgStack.empty()) {
            UndoImgStack.push(RedoImgStack.top());
            RedoImgStack.pop();
            notify();
        }
    }

    void clear() {
        UndoImgStack = std::stack<cv::Mat>();
        RedoImgStack = std::stack<cv::Mat>();
    }

protected:
    void notify() override {
        for (auto &obs: observers)
            obs->update();
    }

private:
    std::vector<Observer *> observers;
    std::stack<cv::Mat> UndoImgStack;
    std::stack<cv::Mat> RedoImgStack;
};

#endif//CMX_IMGSTACK_HPP
