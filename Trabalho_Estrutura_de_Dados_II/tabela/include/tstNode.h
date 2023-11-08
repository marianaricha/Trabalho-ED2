#ifndef TSTNODE_H
#define TSTNODE_H


class TSTNode  
{  
      friend class TSTree;
    /** Constructor **/
    public:  
        public:TSTNode(char data)  
        {  
            this->data = data;  
            this->isEnd = false;  
            this->left = nullptr;  
            this->middle = nullptr;  
            this->right = nullptr;  
        }     
    private:
        char data;  
        bool isEnd;  
        TSTNode *left, *middle, *right;   
};   

#endif
