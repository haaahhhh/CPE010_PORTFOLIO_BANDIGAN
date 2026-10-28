#ifndef GT_H
#define GT_H
#include <vector>

template <typename T>
class GeneralTree{
    private:
        T key;
        std::vector<GeneralTree<T>*> children;
        
    public:
        GeneralTree(T key);
        void insertChild(T newNode);
        
        GeneralTree<T>* getChild(T nodee);
        void preOrder();
        void inOrder();
        void postOrder();

        bool preOrder(T node);
        bool postOrder(T node);
        bool inOrder(T node);
        void findData(int choice, T node);
};

template  <typename T>
GeneralTree<T>::GeneralTree(T value){
    key = value;
}

template <typename T>
void GeneralTree<T>::insertChild(T newNode){
    children.push_back(new GeneralTree<T>(newNode));
}

template<typename T>
GeneralTree<T>* GeneralTree<T>::getChild(T node){
    for(int i =0; i<children.size();i++){
        if(children[i]->key == node){
            return children[i];
        }
    }
    return nullptr;
}
template <typename T>
void GeneralTree<T>::preOrder(){
    std::cout << key << " ";
    for(int i = 0; i<children.size();i++){
        children[i]->preOrder();
    }
}

template <typename T>
void GeneralTree<T>::postOrder(){
    for(int i = 0; i<children.size();i++){
        children[i]->postOrder();
    }
    std::cout << key << " ";
}

template <typename T>
void GeneralTree<T>::inOrder(){
    if(children.size() != 0){
        children[0]->inOrder();
    }
    std::cout << key << " ";
    for(int i = 1; i<children.size();i++){
        children[i]->inOrder();
    }
}

template <typename T>
bool GeneralTree<T>::preOrder(T node){
    if(key == node){
        return true;
    }
    for(int i = 0; i<children.size();i++){
        if(children[i]->preOrder(node)){
            return true;
        }
    }
    
    return false;
}
template <typename T>
bool GeneralTree<T>::postOrder(T node){
    for(int i = 0; i<children.size();i++){
        if(children[i]->postOrder(node)){
            return true;
        }
    }
    if(key == node){
        return true;
    }
    
    return false;
}
template <typename T>
bool GeneralTree<T>::inOrder(T node){
    if(children.size() != 0){
       if(children[0]->inOrder(node)){
            return true;
        }
    }
    if(key == node){
        return true;
    }
    for(int i = 1; i<children.size();i++){
        if(children[i]->inOrder(node)){
            return true;
        }
    }
    return false;
}

template <typename T>
void GeneralTree<T>::findData(int choice, T node){
    bool found = false;
    if(choice == 1){
        std::cout <<std::endl;
        std::cout << "Finding " << node <<" using Pre-Order Traversal.\n";
        found = preOrder(node);
    }else if(choice == 2){
        std::cout <<std::endl;
        std::cout << "Finding " << node <<" using Post-Order Traversal.\n";
        found = postOrder(node);
    }else if(choice == 3){
        std::cout <<std::endl;
        std::cout << "Finding " << node <<" using Inn-Order Traversal.\n";
        found = inOrder(node);
    }else{
        std::cout <<std::endl;
        std::cout << "Invalid input\n";
    }

    if(found){
        std::cout<< node << " was found!"<< std::endl;
    }else{
        std::cout<< node << " was not found"<< std::endl;
    }
   
}

#endif