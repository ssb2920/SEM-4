#include<stdio.h>
#include<stdlib.h>
 
int findLRU(int time[], int n)
{
      int i, minimum = time[0], pos = 0;
      for(i = 1; i < n; ++i)
      {
            if(time[i] < minimum)
            {
                  minimum = time[i];
                  pos = i;
            }
      }     
      return pos;
}
 
int main()
{
      int nof, nop, frames[10], pages[30], counter=0, time[10], f1, f2, i, j, pos, faults=0;
      printf("Enter number of frames: ");
      scanf("%d", &nof);
      printf("Enter number of pages: ");
      scanf("%d", &nop);
      printf("Enter reference string: ");
      for(i = 0; i < nop; ++i)
      {
            scanf("%d", &pages[i]);
      }
    
      for(i = 0; i < nof; ++i)
      {
            frames[i] = -1;
      }
    
      
      for(i = 0; i < nop; ++i)
      {
            f1 = f2 = 0;
            for(j = 0; j < nop; ++j)
            {
                  if(frames[j] == pages[i])
                  {
                        counter++;
                        time[j] = counter;
                        f1 = f2 = 1;
                        break;
                  }
            }
      
            if(f1 == 0)
            {
                  for(j = 0; j < nof; ++j)
                  {
                        if(frames[j] == -1)
                        {
                              counter++;
                              faults++;
                              frames[j] = pages[i];
                              time[j] = counter;
                              f2 = 1;
                              break;
                        }
                  }     
            }
      
            if(f2 == 0)
            {
                  pos = findLRU(time, nof);
                  counter++;
                  faults++;
                  frames[pos] = pages[i];
                  time[pos] = counter;
            }
            
            printf("\n");
            
            for(j = 0; j < nof; ++j)
            {
                  printf("%d\t", frames[j]);
            }
      }
      
      printf("\n\nTotal Page Faults = %d", faults);
      return 0;
}

