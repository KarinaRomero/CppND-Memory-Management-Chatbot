
#include "graphedge.h"
#include "graphnode.h"


GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    /* Activity 0 -> find the BUG: 
        the chatbot instance is not owned, 
        following the rules,
        the responsability to delete is not from here. Karina Romero.*/
    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge* edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    /* Activity 4 -> Moving Smart Pointers: 
        moving the edge to this class, 
        this function (AddEdgeToChildNode) 
        is called from ChatLogic. Karina Romero.*/
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    /* Activity 5 -> Moving the ChatBot: 
        moving the chatbot into this GraphNode. Karina Romero.*/
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    /* Activity 5 -> Moving the ChatBot: 
        moving the chatbot into this GraphNode 
        this function (MoveChatbotToNewNode) 
        is called from chatbot. Karina Romero.*/
    newNode->MoveChatbotHere(std::move(_chatBot));

    /* Activity 5 -> Moving the ChatBot: 
        this is not necesary now. Karina Romero.*/
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    /* Activity 4 -> Moving Smart Pointers: 
        returning the pointer into the unique_ptr. Karina Romero.*/
    return (_childEdges[index]).get();

    ////
    //// EOF STUDENT CODE
}