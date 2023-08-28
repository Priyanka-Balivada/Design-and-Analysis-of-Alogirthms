#include<iostream>
 
using namespace std;
 
int main()
{
    int windowSize,frameSize,frames[50];
 
    cout<<"Enter window size: ";
    cin>>windowSize;
 
    cout<<"\nEnter no. of frames: ";
    cin>>frameSize;
 
    cout<<"\nEnter "<<frameSize<<" frames: ";
 
    for(int i=1;i<=frameSize;i++)
        cin>>frames[i];
 
    cout<<"\n\n****** Wait for acknowledgement by after sending "<<windowSize<<" frames ******\n\n";
 
    for(int i=1;i<=frameSize;i++)
    {
        if(i%windowSize==0)
        {
            cout<<frames[i]<<"\n";
            cout<<"Acknowledgement received\n\n";
        }
        else
            cout<<frames[i]<<" ";
    }
 
    if(frameSize%windowSize!=0)
        cout<<"\nAcknowledgement received\n";
 
    return 0;
}
