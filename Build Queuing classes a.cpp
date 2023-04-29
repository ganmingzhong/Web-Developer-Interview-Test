#include <iostream>

using namespace std;

class IQueuable{
protected:
  int AllocateSize;
  string * array ;

public:
  virtual string* enqueue(string item) =0;
  virtual string dequeue() =0;
  virtual int getSize()=0;
  string * getQueue()
  {
    return array;
  }
};

class LIFOQUEUE :public IQueuable
{
  private:
    int front=0,end=0;
  public:
    LIFOQUEUE(int size)
    {
      AllocateSize=size;
      array = new string[size];
    }

    string* enqueue(string item);
    
    string dequeue();

    int getSize();
   

    virtual ~LIFOQUEUE() {
        delete[] array;
    }
};

class FIFOQUEUE :public IQueuable
{
  private:
    int front=0,end=0;
  public:
    FIFOQUEUE(int size)
    {
      AllocateSize=size;
      array = new string[size];
    }

    string* enqueue(string item);
    
    string dequeue();

    int getSize();

    virtual ~FIFOQUEUE() {
        delete[] array;
    }

};


string* LIFOQUEUE:: enqueue(string item)
    {
      if(end<AllocateSize)
      {
        array[end]=item;
         end++;
      }

     else
      {
        cout<<"The Stack is full.";
      }
      

      return array;
    }

string LIFOQUEUE :: dequeue()
    {
      string temp;
      
      if(end==front)
      {
        cout<<"The Stack is empty";
      }
      else
      {
        end--;
        temp=array[end];
        string * newArray= new string[AllocateSize];
        for(int i=0; i<end;i++)
        {
          newArray[i]=array[i];
        }
        array=newArray;
      }
      return temp;
    }

int LIFOQUEUE:: getSize()
{
  return end;
}

string* FIFOQUEUE:: enqueue(string item)
    {
      if(end<AllocateSize)
      {
        array[end]=item;
         end++;
      }

     else
      {
        cout<<"The Stack is full.";
      }
      

      return array;
    }

string FIFOQUEUE :: dequeue()
    {
      string temp;
      
      if(front==end)
      {
        cout<<"The Stack is empty";
      }
      else
      {
        temp=array[front];
        end--;
        string * newArray= new string[AllocateSize];
        for(int i=0; i<end;i++)
        {
          newArray[i]=array[i+1];
        }
        array=newArray;
      }
      return temp;
    }

int FIFOQUEUE:: getSize()
{
  return end;
}

int main() {
	// Create a LIFO object
  cout<<"\nLIFO\n";
  LIFOQUEUE LIFO(3);
  // enqueue 
  string * arrayLIFO=LIFO.enqueue("cow");
  arrayLIFO=LIFO.enqueue("snake");
  arrayLIFO=LIFO.enqueue("shark");

  //dequeue
  string itemL = LIFO.dequeue();
  
  //getSize
  int sizeLIFO=LIFO.getSize();

  //getQueue
  string * queueL=LIFO.getQueue();
  
  for(int i=0;i<sizeLIFO;i++)
  {
    cout<<queueL[i]<<'\n';
  }

  // Create a FIFO object
  cout<<"\nFIFO\n";
  FIFOQUEUE FIFO(3);
  // enqueue 
  string * arrayFIFO=FIFO.enqueue("cow");
  arrayFIFO=FIFO.enqueue("snake");
  arrayFIFO=FIFO.enqueue("shark");

  //dequeue
  string itemF = FIFO.dequeue();

  //getSize
  int sizeFIFO=FIFO.getSize();

  //getQueue
  string * queueF=FIFO.getQueue();
  
  for(int i=0;i<sizeFIFO;i++)
  {
    cout<<queueF[i]<<'\n';
  }
  return 0;
};
