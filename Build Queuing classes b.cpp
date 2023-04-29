#include <iostream>
#include <vector>
using namespace std;

class IQueuable{
protected: 
  int maxSize;
  vector<string> array ;

public:
  virtual vector <string> enqueue(string item) =0;
  virtual string dequeue() =0;
  virtual int getSize()=0;
  vector <string> getQueue()
  {
    return array;
  }
};

class LIFOQUEUE :public IQueuable
{
  public:
    LIFOQUEUE(int size)
    {
      maxSize=size;     
    }

    vector <string> enqueue(string item);
    string dequeue();
    int getSize();

};

class FIFOQUEUE :public IQueuable
{
  public:
    FIFOQUEUE(int size)
    {
      maxSize=size;
  //array = new string[size];
      
    }

    vector <string> enqueue(string item);
    string dequeue();
    int getSize();

};

vector <string> LIFOQUEUE:: enqueue(string item)
    {
      if(array.size()<maxSize)
      {
        array.push_back(item);
      }
      else
      {
        cout<<"The Stack is full.\n";
      }
      return array;
    }

string LIFOQUEUE :: dequeue()
    {
      string temp;
      
      if(array.empty())
      {
        cout<<"The Stack is empty\n";
      }
      else
      {
        temp=array.back();
        array.pop_back();
      }
      return temp;
    }

int LIFOQUEUE:: getSize()
{
  return array.size();
}

vector <string> FIFOQUEUE:: enqueue(string item)
    {
      if(array.size()<maxSize)
      {
        array.push_back(item);
      }
      else
      {
        cout<<"The Stack is full.\n";
      }
      

      return array;
    }

string FIFOQUEUE :: dequeue()
    {
      string temp;
      
      if(array.empty())
      {
        cout<<"The Stack is empty\n";
      }
      else
      {
        temp=array.front();
        array.erase(array.begin());
      }
      return temp;
    }


int FIFOQUEUE:: getSize()
{
  return array.size();
}

int main() {
	// Create a LIFO object
  cout<<"\nLIFO\n";
  LIFOQUEUE LIFO(3);
  // enqueue 
  vector arrayLIFO=LIFO.enqueue("cow");
  arrayLIFO=LIFO.enqueue("snake");
  arrayLIFO=LIFO.enqueue("shark");
  //dequeue
  string itemL = LIFO.dequeue();

  //getSize
  int sizeLIFO=LIFO.getSize();

  //getQueue
  vector <string> queueL=LIFO.getQueue();
  
  for(int i=0;i<sizeLIFO;i++)
  {
    cout<<queueL[i]<<'\n';
  }
  cout<<'\n';
  // Create a FIFO object
  cout<<"\nFIFO\n";
  FIFOQUEUE FIFO(3);
  // enqueue 
  vector <string> arrayFIFO=FIFO.enqueue("cow");
  arrayFIFO=FIFO.enqueue("snake");
  arrayFIFO=FIFO.enqueue("shark");

  //dequeue
  string itemF = FIFO.dequeue();

  //getSize
  int sizeFIFO=FIFO.getSize();

  //getQueue
  vector <string> queueF=FIFO.getQueue();
  
  for(int i=0;i<sizeFIFO;i++)
  {
    cout<<queueF[i]<<'\n';
  }
  return 0;
};
