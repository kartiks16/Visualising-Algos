#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>

char algoname[20]="";
float a=0,c=0;
int tot=400;
float arr[5000];
float x_dist=0;
float b[5000];
int col=0,start;

class data{
public:
void numbers();
void insertionsort(float[],int);
void bubblesort(float[],int);
void mergesort(float *,int,int);
void merge(float *,int,int,int);
void selectionsort(float[],int);
void quick_sort(float[],int,int);
int partition(float[],int,int);
void heapify(float arr[], int n, int i);
void heapSort(float arr[], int n);
void draw();
};


int main()
{

cin>>start;
data obj;
int gd=DETECT, gm,n=tot;
clrscr();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
obj.numbers();

obj.bubblesort(arr,n);
delay(1000);
obj.numbers();
obj.mergesort(arr,0,n-1);
delay(1000);
obj.numbers();

obj.quick_sort(arr,0,n-1);
delay(1000);
obj.numbers();
obj.selectionsort(arr,n);
delay(1000);
obj.numbers();
obj.insertionsort(arr,n);
delay(1000);
obj.numbers();
obj.heapSort(arr,n);
delay(1000);
return 0;
}





void data::draw()
{
x_dist=0;
int j;
cleardevice();
outtextxy(20,20,algoname);
	for(j=0;j<tot;j++)
		{
		line(x_dist/2,450,x_dist/2,450-arr[j]*3);
		x_dist+=3;
		}

}





void data::bubblesort(float a[] ,int n)
{

strcpy(algoname,"BubbleSort");

 setcolor(RED);
 for(int k=0;k<n;++k)
 {
  for(int l=k+1;l<n;++l)
  {

   if(a[k] > a[l])
   {
    int temp;
    temp=arr[k];
    a[k]=a[l];
    a[l]=temp;

    draw();

   }
  }
 }

}









void data::mergesort(float a[],int i,int j)
{
strcpy(algoname,"MergeSort");
 setcolor(YELLOW);
   int mid;
   if(i<j)
   {
      mid=(i+j)/2;
      mergesort(a,i,mid);
      mergesort(a,mid+1,j);
      merge(a,i,mid,j);
   }

}


void data::merge(float a[],int low,int mid ,int high)
{
   int h,i,j,k;
   h=low;
   i=low;
    j=mid+1;
   while(h<=mid && j<=high)
   {
      if(a[h]<=a[j])
	 b[i]=a[h++];
      else
	 b[i]=a[j++];
      i++;
   }

   if( h > mid)
      for(k=j;k<=high;k++)
	b[i++]=a[k];
   else
      for(k=h;k<=mid;k++)
	 b[i++]=a[k];


   for(k=low;k<=high;k++)
   {  a[k]=b[k];

   draw();
   }

}


void data::quick_sort(float a[],int l,int u)
{
strcpy(algoname,"QuickSort");
setcolor(RED);
    int j;
    if(l<u)
    {
	j=partition(a,l,u);
	quick_sort(a,l,j-1);
	quick_sort(a,j+1,u);


    }

}


int data::partition(float a[],int l,int u)
{
    float v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
	do
	    i++;

	while(a[i]<v&&i<=u);

	do
	    j--;
	while(v<a[j]);

	if(i<j)
	{
	    temp=a[i];
	    a[i]=a[j];
	    a[j]=temp;
	}
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

     draw();
    return(j);
}




void data::selectionsort(float a[],int n)
{
strcpy(algoname,"SelectionSort");
 setcolor(YELLOW);
     int i,loc,j,min,temp;
for(i=0;i<n;i++)
    {
	min=a[i];
	loc=i;
	for(j=i+1;j<n;j++)
	{
	    if(min>a[j])
	    {
		min=a[j];
		loc=j;
	    }
	}

	temp=a[i];
	a[i]=a[loc];
	a[loc]=temp;

draw();

    }

 }




void data::insertionsort(float a[],int n)
{
strcpy(algoname,"InsertionSort");
 setcolor(RED);
int temp,i,j;
 for(i=1;i<=n-1;i++)
    {
	temp=a[i];
	j=i-1;

	while((temp<arr[j])&&(j>=0))
	{
	    a[j+1]=a[j];    //moves element forward
	    j=j-1;
	}

	a[j+1]=temp;    //insert element in proper place

draw();


    }

}




void data::heapify(float arr[], int n, int i) {
   int temp;
   int largest = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;
   if (l < n && arr[l] > arr[largest])
      largest = l;
   if (r < n && arr[r] > arr[largest])
      largest = r;
   if (largest != i) {
      temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;
      heapify(arr, n, largest);
   }
}
void data::heapSort(float arr[], int n)
{
strcpy(algoname,"HeapSort");
 setcolor(YELLOW);
   int temp;
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

   for (int j = n - 1; j >= 0; j--) {
      temp = arr[0];
      arr[0] = arr[j];
      arr[j] = temp;
      heapify(arr, j, 0);

draw();

   }

}



 void data:: numbers()
 {

arr[ 0 ]= 53.01 ;
arr[ 1 ]= 73.25 ;
arr[ 2 ]= 69.96 ;
arr[ 3 ]= 79.28 ;
arr[ 4 ]= 26.15 ;
arr[ 5 ]= 78.98 ;
arr[ 6 ]= 73.73 ;
arr[ 7 ]= 85.7 ;
arr[ 8 ]= 99.36 ;
arr[ 9 ]= 6.01 ;
arr[ 10 ]= 76.98 ;
arr[ 11 ]= 1.53 ;
arr[ 12 ]= 80.17 ;
arr[ 13 ]= 28.7 ;
arr[ 14 ]= 43.21 ;
arr[ 15 ]= 65.52 ;
arr[ 16 ]= 11.66 ;
arr[ 17 ]= 86.47 ;
arr[ 18 ]= 31.08 ;
arr[ 19 ]= 24.81 ;
arr[ 20 ]= 38.38 ;
arr[ 21 ]= 41.0 ;
arr[ 22 ]= 25.06 ;
arr[ 23 ]= 2.89 ;
arr[ 24 ]= 34.1 ;
arr[ 25 ]= 17.53 ;
arr[ 26 ]= 9.6 ;
arr[ 27 ]= 64.7 ;
arr[ 28 ]= 3.15 ;
arr[ 29 ]= 91.72 ;
arr[ 30 ]= 71.04 ;
arr[ 31 ]= 67.07 ;
arr[ 32 ]= 31.88 ;
arr[ 33 ]= 39.48 ;
arr[ 34 ]= 61.0 ;
arr[ 35 ]= 75.92 ;
arr[ 36 ]= 82.68 ;
arr[ 37 ]= 74.78 ;
arr[ 38 ]= 2.56 ;
arr[ 39 ]= 4.45 ;
arr[ 40 ]= 43.85 ;
arr[ 41 ]= 74.01 ;
arr[ 42 ]= 35.68 ;
arr[ 43 ]= 88.25 ;
arr[ 44 ]= 69.62 ;
arr[ 45 ]= 49.64 ;
arr[ 46 ]= 44.25 ;
arr[ 47 ]= 31.28 ;
arr[ 48 ]= 56.21 ;
arr[ 49 ]= 84.66 ;
arr[ 50 ]= 96.1 ;
arr[ 51 ]= 0.47 ;
arr[ 52 ]= 60.75 ;
arr[ 53 ]= 72.11 ;
arr[ 54 ]= 52.63 ;
arr[ 55 ]= 50.4 ;
arr[ 56 ]= 49.09 ;
arr[ 57 ]= 17.96 ;
arr[ 58 ]= 86.0 ;
arr[ 59 ]= 92.31 ;
arr[ 60 ]= 61.61 ;
arr[ 61 ]= 81.08 ;
arr[ 62 ]= 70.8 ;
arr[ 63 ]= 88.61 ;
arr[ 64 ]= 24.98 ;
arr[ 65 ]= 21.97 ;
arr[ 66 ]= 58.2 ;
arr[ 67 ]= 71.26 ;
arr[ 68 ]= 34.52 ;
arr[ 69 ]= 77.25 ;
arr[ 70 ]= 58.28 ;
arr[ 71 ]= 89.91 ;
arr[ 72 ]= 51.72 ;
arr[ 73 ]= 44.14 ;
arr[ 74 ]= 96.28 ;
arr[ 75 ]= 96.51 ;
arr[ 76 ]= 68.39 ;
arr[ 77 ]= 98.92 ;
arr[ 78 ]= 26.07 ;
arr[ 79 ]= 70.45 ;
arr[ 80 ]= 23.62 ;
arr[ 81 ]= 62.64 ;
arr[ 82 ]= 90.93 ;
arr[ 83 ]= 37.33 ;
arr[ 84 ]= 18.43 ;
arr[ 85 ]= 47.21 ;
arr[ 86 ]= 70.41 ;
arr[ 87 ]= 67.87 ;
arr[ 88 ]= 74.14 ;
arr[ 89 ]= 76.86 ;
arr[ 90 ]= 93.35 ;
arr[ 91 ]= 17.72 ;
arr[ 92 ]= 12.11 ;
arr[ 93 ]= 9.34 ;
arr[ 94 ]= 5.77 ;
arr[ 95 ]= 66.21 ;
arr[ 96 ]= 2.38 ;
arr[ 97 ]= 58.9 ;
arr[ 98 ]= 74.47 ;
arr[ 99 ]= 15.6 ;
arr[ 100 ]= 21.72 ;
arr[ 101 ]= 57.09 ;
arr[ 102 ]= 14.37 ;
arr[ 103 ]= 52.29 ;
arr[ 104 ]= 26.91 ;
arr[ 105 ]= 33.53 ;
arr[ 106 ]= 12.94 ;
arr[ 107 ]= 57.2 ;
arr[ 108 ]= 40.46 ;
arr[ 109 ]= 33.36 ;
arr[ 110 ]= 93.41 ;
arr[ 111 ]= 83.11 ;
arr[ 112 ]= 54.78 ;
arr[ 113 ]= 46.41 ;
arr[ 114 ]= 76.99 ;
arr[ 115 ]= 79.06 ;
arr[ 116 ]= 38.03 ;
arr[ 117 ]= 10.66 ;
arr[ 118 ]= 22.16 ;
arr[ 119 ]= 45.59 ;
arr[ 120 ]= 68.14 ;
arr[ 121 ]= 52.88 ;
arr[ 122 ]= 81.78 ;
arr[ 123 ]= 94.35 ;
arr[ 124 ]= 46.58 ;
arr[ 125 ]= 6.06 ;
arr[ 126 ]= 75.4 ;
arr[ 127 ]= 5.12 ;
arr[ 128 ]= 55.34 ;
arr[ 129 ]= 28.9 ;
arr[ 130 ]= 99.72 ;
arr[ 131 ]= 5.43 ;
arr[ 132 ]= 85.42 ;
arr[ 133 ]= 60.14 ;
arr[ 134 ]= 28.19 ;
arr[ 135 ]= 78.64 ;
arr[ 136 ]= 93.81 ;
arr[ 137 ]= 66.17 ;
arr[ 138 ]= 88.53 ;
arr[ 139 ]= 53.93 ;
arr[ 140 ]= 59.19 ;
arr[ 141 ]= 74.73 ;
arr[ 142 ]= 93.64 ;
arr[ 143 ]= 12.42 ;
arr[ 144 ]= 93.65 ;
arr[ 145 ]= 17.79 ;
arr[ 146 ]= 50.08 ;
arr[ 147 ]= 35.49 ;
arr[ 148 ]= 66.42 ;
arr[ 149 ]= 40.19 ;
arr[ 150 ]= 6.2 ;
arr[ 151 ]= 29.3 ;
arr[ 152 ]= 70.34 ;
arr[ 153 ]= 63.29 ;
arr[ 154 ]= 60.9 ;
arr[ 155 ]= 35.03 ;
arr[ 156 ]= 9.21 ;
arr[ 157 ]= 55.9 ;
arr[ 158 ]= 14.41 ;
arr[ 159 ]= 28.63 ;
arr[ 160 ]= 23.23 ;
arr[ 161 ]= 45.1 ;
arr[ 162 ]= 89.9 ;
arr[ 163 ]= 43.08 ;
arr[ 164 ]= 23.32 ;
arr[ 165 ]= 52.39 ;
arr[ 166 ]= 37.72 ;
arr[ 167 ]= 65.72 ;
arr[ 168 ]= 60.01 ;
arr[ 169 ]= 14.14 ;
arr[ 170 ]= 63.38 ;
arr[ 171 ]= 23.52 ;
arr[ 172 ]= 87.23 ;
arr[ 173 ]= 94.78 ;
arr[ 174 ]= 77.89 ;
arr[ 175 ]= 70.83 ;
arr[ 176 ]= 83.3 ;
arr[ 177 ]= 82.28 ;
arr[ 178 ]= 27.47 ;
arr[ 179 ]= 33.98 ;
arr[ 180 ]= 61.94 ;
arr[ 181 ]= 74.41 ;
arr[ 182 ]= 19.65 ;
arr[ 183 ]= 7.41 ;
arr[ 184 ]= 57.67 ;
arr[ 185 ]= 29.8 ;
arr[ 186 ]= 96.26 ;
arr[ 187 ]= 97.67 ;
arr[ 188 ]= 53.14 ;
arr[ 189 ]= 92.68 ;
arr[ 190 ]= 59.04 ;
arr[ 191 ]= 11.81 ;
arr[ 192 ]= 3.52 ;
arr[ 193 ]= 36.71 ;
arr[ 194 ]= 27.71 ;
arr[ 195 ]= 95.77 ;
arr[ 196 ]= 58.61 ;
arr[ 197 ]= 60.7 ;
arr[ 198 ]= 2.54 ;
arr[ 199 ]= 9.41 ;
arr[ 200 ]= 13.81 ;
arr[ 201 ]= 64.97 ;
arr[ 202 ]= 22.15 ;
arr[ 203 ]= 99.74 ;
arr[ 204 ]= 36.99 ;
arr[ 205 ]= 86.54 ;
arr[ 206 ]= 24.8 ;
arr[ 207 ]= 47.6 ;
arr[ 208 ]= 58.13 ;
arr[ 209 ]= 80.25 ;
arr[ 210 ]= 5.25 ;
arr[ 211 ]= 83.84 ;
arr[ 212 ]= 35.7 ;
arr[ 213 ]= 54.59 ;
arr[ 214 ]= 74.27 ;
arr[ 215 ]= 96.42 ;
arr[ 216 ]= 44.53 ;
arr[ 217 ]= 18.8 ;
arr[ 218 ]= 80.98 ;
arr[ 219 ]= 43.69 ;
arr[ 220 ]= 13.33 ;
arr[ 221 ]= 68.37 ;
arr[ 222 ]= 29.79 ;
arr[ 223 ]= 89.93 ;
arr[ 224 ]= 99.54 ;
arr[ 225 ]= 12.27 ;
arr[ 226 ]= 19.12 ;
arr[ 227 ]= 13.94 ;
arr[ 228 ]= 43.4 ;
arr[ 229 ]= 7.53 ;
arr[ 230 ]= 34.98 ;
arr[ 231 ]= 77.37 ;
arr[ 232 ]= 59.26 ;
arr[ 233 ]= 20.6 ;
arr[ 234 ]= 91.44 ;
arr[ 235 ]= 43.57 ;
arr[ 236 ]= 80.52 ;
arr[ 237 ]= 75.1 ;
arr[ 238 ]= 78.05 ;
arr[ 239 ]= 58.04 ;
arr[ 240 ]= 27.33 ;
arr[ 241 ]= 82.78 ;
arr[ 242 ]= 44.21 ;
arr[ 243 ]= 78.99 ;
arr[ 244 ]= 98.9 ;
arr[ 245 ]= 35.73 ;
arr[ 246 ]= 9.08 ;
arr[ 247 ]= 66.69 ;
arr[ 248 ]= 59.69 ;
arr[ 249 ]= 19.85 ;
arr[ 250 ]= 5.87 ;
arr[ 251 ]= 78.74 ;
arr[ 252 ]= 63.32 ;
arr[ 253 ]= 60.25 ;
arr[ 254 ]= 31.15 ;
arr[ 255 ]= 67.36 ;
arr[ 256 ]= 72.51 ;
arr[ 257 ]= 36.95 ;
arr[ 258 ]= 46.27 ;
arr[ 259 ]= 73.34 ;
arr[ 260 ]= 10.53 ;
arr[ 261 ]= 20.58 ;
arr[ 262 ]= 14.69 ;
arr[ 263 ]= 59.3 ;
arr[ 264 ]= 40.21 ;
arr[ 265 ]= 68.78 ;
arr[ 266 ]= 30.11 ;
arr[ 267 ]= 27.88 ;
arr[ 268 ]= 33.93 ;
arr[ 269 ]= 17.75 ;
arr[ 270 ]= 22.73 ;
arr[ 271 ]= 0.23 ;
arr[ 272 ]= 53.34 ;
arr[ 273 ]= 43.51 ;
arr[ 274 ]= 33.95 ;
arr[ 275 ]= 11.59 ;
arr[ 276 ]= 60.78 ;
arr[ 277 ]= 7.97 ;
arr[ 278 ]= 73.22 ;
arr[ 279 ]= 39.21 ;
arr[ 280 ]= 25.86 ;
arr[ 281 ]= 10.96 ;
arr[ 282 ]= 66.87 ;
arr[ 283 ]= 63.73 ;
arr[ 284 ]= 81.85 ;
arr[ 285 ]= 92.9 ;
arr[ 286 ]= 44.6 ;
arr[ 287 ]= 71.81 ;
arr[ 288 ]= 58.35 ;
arr[ 289 ]= 39.85 ;
arr[ 290 ]= 92.0 ;
arr[ 291 ]= 47.56 ;
arr[ 292 ]= 84.87 ;
arr[ 293 ]= 21.62 ;
arr[ 294 ]= 33.3 ;
arr[ 295 ]= 30.96 ;
arr[ 296 ]= 34.41 ;
arr[ 297 ]= 10.61 ;
arr[ 298 ]= 70.06 ;
arr[ 299 ]= 34.2 ;
arr[ 300 ]= 49.32 ;
arr[ 301 ]= 93.98 ;
arr[ 302 ]= 57.63 ;
arr[ 303 ]= 38.18 ;
arr[ 304 ]= 26.89 ;
arr[ 305 ]= 51.85 ;
arr[ 306 ]= 95.65 ;
arr[ 307 ]= 6.04 ;
arr[ 308 ]= 8.64 ;
arr[ 309 ]= 35.85 ;
arr[ 310 ]= 27.59 ;
arr[ 311 ]= 18.24 ;
arr[ 312 ]= 86.22 ;
arr[ 313 ]= 33.35 ;
arr[ 314 ]= 41.87 ;
arr[ 315 ]= 25.11 ;
arr[ 316 ]= 99.0 ;
arr[ 317 ]= 85.28 ;
arr[ 318 ]= 81.68 ;
arr[ 319 ]= 55.39 ;
arr[ 320 ]= 88.86 ;
arr[ 321 ]= 44.68 ;
arr[ 322 ]= 60.62 ;
arr[ 323 ]= 78.76 ;
arr[ 324 ]= 73.95 ;
arr[ 325 ]= 92.95 ;
arr[ 326 ]= 61.04 ;
arr[ 327 ]= 59.51 ;
arr[ 328 ]= 82.58 ;
arr[ 329 ]= 65.24 ;
arr[ 330 ]= 40.41 ;
arr[ 331 ]= 47.38 ;
arr[ 332 ]= 59.44 ;
arr[ 333 ]= 80.39 ;
arr[ 334 ]= 82.23 ;
arr[ 335 ]= 94.77 ;
arr[ 336 ]= 50.77 ;
arr[ 337 ]= 11.76 ;
arr[ 338 ]= 92.64 ;
arr[ 339 ]= 98.93 ;
arr[ 340 ]= 36.96 ;
arr[ 341 ]= 36.92 ;
arr[ 342 ]= 20.1 ;
arr[ 343 ]= 76.36 ;
arr[ 344 ]= 53.55 ;
arr[ 345 ]= 97.52 ;
arr[ 346 ]= 17.65 ;
arr[ 347 ]= 36.11 ;
arr[ 348 ]= 25.72 ;
arr[ 349 ]= 7.98 ;
arr[ 350 ]= 25.2 ;
arr[ 351 ]= 80.72 ;
arr[ 352 ]= 75.9 ;
arr[ 353 ]= 21.82 ;
arr[ 354 ]= 92.69 ;
arr[ 355 ]= 47.59 ;
arr[ 356 ]= 8.12 ;
arr[ 357 ]= 8.08 ;
arr[ 358 ]= 73.59 ;
arr[ 359 ]= 5.56 ;
arr[ 360 ]= 52.53 ;
arr[ 361 ]= 14.91 ;
arr[ 362 ]= 95.54 ;
arr[ 363 ]= 30.76 ;
arr[ 364 ]= 58.51 ;
arr[ 365 ]= 96.36 ;
arr[ 366 ]= 72.79 ;
arr[ 367 ]= 65.56 ;
arr[ 368 ]= 93.51 ;
arr[ 369 ]= 30.1 ;
arr[ 370 ]= 49.56 ;
arr[ 371 ]= 49.58 ;
arr[ 372 ]= 44.06 ;
arr[ 373 ]= 50.91 ;
arr[ 374 ]= 0.56 ;
arr[ 375 ]= 92.81 ;
arr[ 376 ]= 69.06 ;
arr[ 377 ]= 34.3 ;
arr[ 378 ]= 16.63 ;
arr[ 379 ]= 81.97 ;
arr[ 380 ]= 74.23 ;
arr[ 381 ]= 90.64 ;
arr[ 382 ]= 87.81 ;
arr[ 383 ]= 90.89 ;
arr[ 384 ]= 97.97 ;
arr[ 385 ]= 1.16 ;
arr[ 386 ]= 12.29 ;
arr[ 387 ]= 30.01 ;
arr[ 388 ]= 39.14 ;
arr[ 389 ]= 59.76 ;
arr[ 390 ]= 27.73 ;
arr[ 391 ]= 66.88 ;
arr[ 392 ]= 13.31 ;
arr[ 393 ]= 35.14 ;
arr[ 394 ]= 39.52 ;
arr[ 395 ]= 66.11 ;
arr[ 396 ]= 95.61 ;
arr[ 397 ]= 5.47 ;
arr[ 398 ]= 11.54 ;
arr[ 399 ]= 45.41 ;
arr[ 400 ]= 87.45 ;
arr[ 401 ]= 2.2 ;
arr[ 402 ]= 38.55 ;
arr[ 403 ]= 4.87 ;
arr[ 404 ]= 73.65 ;
arr[ 405 ]= 96.78 ;
arr[ 406 ]= 92.28 ;
arr[ 407 ]= 19.5 ;
arr[ 408 ]= 47.71 ;
arr[ 409 ]= 6.26 ;
arr[ 410 ]= 76.75 ;
arr[ 411 ]= 27.68 ;
arr[ 412 ]= 85.34 ;
arr[ 413 ]= 98.22 ;
arr[ 414 ]= 60.57 ;
arr[ 415 ]= 32.08 ;
arr[ 416 ]= 99.64 ;
arr[ 417 ]= 5.46 ;
arr[ 418 ]= 33.17 ;
arr[ 419 ]= 82.75 ;
arr[ 420 ]= 91.97 ;
arr[ 421 ]= 84.38 ;
arr[ 422 ]= 31.26 ;
arr[ 423 ]= 90.77 ;
arr[ 424 ]= 0.13 ;
arr[ 425 ]= 70.03 ;
arr[ 426 ]= 95.34 ;
arr[ 427 ]= 8.02 ;
arr[ 428 ]= 32.8 ;
arr[ 429 ]= 38.27 ;
arr[ 430 ]= 28.59 ;
arr[ 431 ]= 85.77 ;
arr[ 432 ]= 21.27 ;
arr[ 433 ]= 96.01 ;
arr[ 434 ]= 29.31 ;
arr[ 435 ]= 42.92 ;
arr[ 436 ]= 76.1 ;
arr[ 437 ]= 89.56 ;
arr[ 438 ]= 64.47 ;
arr[ 439 ]= 30.9 ;
arr[ 440 ]= 19.19 ;
arr[ 441 ]= 26.26 ;
arr[ 442 ]= 85.33 ;
arr[ 443 ]= 42.27 ;
arr[ 444 ]= 25.75 ;
arr[ 445 ]= 81.87 ;
arr[ 446 ]= 82.02 ;
arr[ 447 ]= 28.45 ;
arr[ 448 ]= 7.1 ;
arr[ 449 ]= 97.37 ;
arr[ 450 ]= 43.87 ;
arr[ 451 ]= 54.23 ;
arr[ 452 ]= 83.0 ;
arr[ 453 ]= 48.74 ;
arr[ 454 ]= 43.61 ;
arr[ 455 ]= 39.9 ;
arr[ 456 ]= 31.61 ;
arr[ 457 ]= 68.09 ;
arr[ 458 ]= 83.48 ;
arr[ 459 ]= 36.36 ;
arr[ 460 ]= 27.5 ;
arr[ 461 ]= 68.74 ;
arr[ 462 ]= 8.4 ;
arr[ 463 ]= 3.02 ;
arr[ 464 ]= 42.34 ;
arr[ 465 ]= 24.37 ;
arr[ 466 ]= 29.21 ;
arr[ 467 ]= 23.84 ;
arr[ 468 ]= 19.7 ;
arr[ 469 ]= 60.52 ;
arr[ 470 ]= 21.81 ;
arr[ 471 ]= 81.51 ;
arr[ 472 ]= 81.57 ;
arr[ 473 ]= 50.33 ;
arr[ 474 ]= 20.59 ;
arr[ 475 ]= 10.36 ;
arr[ 476 ]= 4.0 ;
arr[ 477 ]= 16.08 ;
arr[ 478 ]= 9.11 ;
arr[ 479 ]= 94.42 ;
arr[ 480 ]= 20.96 ;
arr[ 481 ]= 70.53 ;
arr[ 482 ]= 47.05 ;
arr[ 483 ]= 86.8 ;
arr[ 484 ]= 36.91 ;
arr[ 485 ]= 54.95 ;
arr[ 486 ]= 74.11 ;
arr[ 487 ]= 18.74 ;
arr[ 488 ]= 62.13 ;
arr[ 489 ]= 11.46 ;
arr[ 490 ]= 41.69 ;
arr[ 491 ]= 22.43 ;
arr[ 492 ]= 82.33 ;
arr[ 493 ]= 16.41 ;
arr[ 494 ]= 3.3 ;
arr[ 495 ]= 50.87 ;
arr[ 496 ]= 22.57 ;
arr[ 497 ]= 20.09 ;
arr[ 498 ]= 59.84 ;
arr[ 499 ]= 61.28 ;
arr[ 500 ]= 83.55 ;
arr[ 501 ]= 43.54 ;
arr[ 502 ]= 51.42 ;
arr[ 503 ]= 32.85 ;
arr[ 504 ]= 83.17 ;
arr[ 505 ]= 94.75 ;
arr[ 506 ]= 59.94 ;
arr[ 507 ]= 66.8 ;
arr[ 508 ]= 45.35 ;
arr[ 509 ]= 94.8 ;
arr[ 510 ]= 57.02 ;
arr[ 511 ]= 27.91 ;
arr[ 512 ]= 89.69 ;
arr[ 513 ]= 33.99 ;
arr[ 514 ]= 74.55 ;
arr[ 515 ]= 88.27 ;
arr[ 516 ]= 43.11 ;
arr[ 517 ]= 87.06 ;
arr[ 518 ]= 43.5 ;
arr[ 519 ]= 76.44 ;
arr[ 520 ]= 89.52 ;
arr[ 521 ]= 57.15 ;
arr[ 522 ]= 82.47 ;
arr[ 523 ]= 70.78 ;
arr[ 524 ]= 17.62 ;
arr[ 525 ]= 93.18 ;
arr[ 526 ]= 85.39 ;
arr[ 527 ]= 40.76 ;
arr[ 528 ]= 17.7 ;
arr[ 529 ]= 90.67 ;
arr[ 530 ]= 99.52 ;
arr[ 531 ]= 57.17 ;
arr[ 532 ]= 67.99 ;
arr[ 533 ]= 64.66 ;
arr[ 534 ]= 86.01 ;
arr[ 535 ]= 35.65 ;
arr[ 536 ]= 73.11 ;
arr[ 537 ]= 86.76 ;
arr[ 538 ]= 65.43 ;
arr[ 539 ]= 19.1 ;
arr[ 540 ]= 83.08 ;
arr[ 541 ]= 6.03 ;
arr[ 542 ]= 88.5 ;
arr[ 543 ]= 30.02 ;
arr[ 544 ]= 26.63 ;
arr[ 545 ]= 3.36 ;
arr[ 546 ]= 11.33 ;
arr[ 547 ]= 30.77 ;
arr[ 548 ]= 60.06 ;
arr[ 549 ]= 55.71 ;
arr[ 550 ]= 57.97 ;
arr[ 551 ]= 2.5 ;
arr[ 552 ]= 81.15 ;
arr[ 553 ]= 20.87 ;
arr[ 554 ]= 90.19 ;
arr[ 555 ]= 94.44 ;
arr[ 556 ]= 85.4 ;
arr[ 557 ]= 11.61 ;
arr[ 558 ]= 68.52 ;
arr[ 559 ]= 11.91 ;
arr[ 560 ]= 62.27 ;
arr[ 561 ]= 82.03 ;
arr[ 562 ]= 15.26 ;
arr[ 563 ]= 91.86 ;
arr[ 564 ]= 77.5 ;
arr[ 565 ]= 84.86 ;
arr[ 566 ]= 94.06 ;
arr[ 567 ]= 5.76 ;
arr[ 568 ]= 31.1 ;
arr[ 569 ]= 66.83 ;
arr[ 570 ]= 40.83 ;
arr[ 571 ]= 48.06 ;
arr[ 572 ]= 1.99 ;
arr[ 573 ]= 95.67 ;
arr[ 574 ]= 78.73 ;
arr[ 575 ]= 46.29 ;
arr[ 576 ]= 41.12 ;
arr[ 577 ]= 84.8 ;
arr[ 578 ]= 90.55 ;
arr[ 579 ]= 13.34 ;
arr[ 580 ]= 54.64 ;
arr[ 581 ]= 48.85 ;
arr[ 582 ]= 62.63 ;
arr[ 583 ]= 82.46 ;
arr[ 584 ]= 54.33 ;
arr[ 585 ]= 8.5 ;
arr[ 586 ]= 70.88 ;
arr[ 587 ]= 55.7 ;
arr[ 588 ]= 1.68 ;
arr[ 589 ]= 7.07 ;
arr[ 590 ]= 92.59 ;
arr[ 591 ]= 2.09 ;
arr[ 592 ]= 80.53 ;
arr[ 593 ]= 68.94 ;
arr[ 594 ]= 78.84 ;
arr[ 595 ]= 64.13 ;
arr[ 596 ]= 83.07 ;
arr[ 597 ]= 66.75 ;
arr[ 598 ]= 76.66 ;
arr[ 599 ]= 65.36 ;
arr[ 600 ]= 54.29 ;
arr[ 601 ]= 65.02 ;
arr[ 602 ]= 61.93 ;
arr[ 603 ]= 27.41 ;
arr[ 604 ]= 91.26 ;
arr[ 605 ]= 50.3 ;
arr[ 606 ]= 9.7 ;
arr[ 607 ]= 63.74 ;
arr[ 608 ]= 92.73 ;
arr[ 609 ]= 13.84 ;
arr[ 610 ]= 33.33 ;
arr[ 611 ]= 48.47 ;
arr[ 612 ]= 97.6 ;
arr[ 613 ]= 19.06 ;
arr[ 614 ]= 63.12 ;
arr[ 615 ]= 34.88 ;
arr[ 616 ]= 7.28 ;
arr[ 617 ]= 29.25 ;
arr[ 618 ]= 0.1 ;
arr[ 619 ]= 90.24 ;
arr[ 620 ]= 8.73 ;
arr[ 621 ]= 90.82 ;
arr[ 622 ]= 74.44 ;
arr[ 623 ]= 23.95 ;
arr[ 624 ]= 76.09 ;
arr[ 625 ]= 99.68 ;
arr[ 626 ]= 78.06 ;
arr[ 627 ]= 80.8 ;
arr[ 628 ]= 59.61 ;
arr[ 629 ]= 63.39 ;
arr[ 630 ]= 25.53 ;
arr[ 631 ]= 47.77 ;
arr[ 632 ]= 18.37 ;
arr[ 633 ]= 63.69 ;
arr[ 634 ]= 44.82 ;
arr[ 635 ]= 49.38 ;
arr[ 636 ]= 67.69 ;
arr[ 637 ]= 9.91 ;
arr[ 638 ]= 35.09 ;
arr[ 639 ]= 87.37 ;
arr[ 640 ]= 24.82 ;
arr[ 641 ]= 88.07 ;
arr[ 642 ]= 93.19 ;
arr[ 643 ]= 84.64 ;
arr[ 644 ]= 91.47 ;
arr[ 645 ]= 62.18 ;
arr[ 646 ]= 17.82 ;
arr[ 647 ]= 34.76 ;
arr[ 648 ]= 76.54 ;
arr[ 649 ]= 95.08 ;
arr[ 650 ]= 30.59 ;
arr[ 651 ]= 14.42 ;
arr[ 652 ]= 48.64 ;
arr[ 653 ]= 91.59 ;
arr[ 654 ]= 99.49 ;
arr[ 655 ]= 16.38 ;
arr[ 656 ]= 80.2 ;
arr[ 657 ]= 18.45 ;
arr[ 658 ]= 91.91 ;
arr[ 659 ]= 52.21 ;
arr[ 660 ]= 64.59 ;
arr[ 661 ]= 36.7 ;
arr[ 662 ]= 66.65 ;
arr[ 663 ]= 88.31 ;
arr[ 664 ]= 85.54 ;
arr[ 665 ]= 62.3 ;
arr[ 666 ]= 90.14 ;
arr[ 667 ]= 84.16 ;
arr[ 668 ]= 82.99 ;
arr[ 669 ]= 86.93 ;
arr[ 670 ]= 43.56 ;
arr[ 671 ]= 98.06 ;
arr[ 672 ]= 71.73 ;
arr[ 673 ]= 40.45 ;
arr[ 674 ]= 22.59 ;
arr[ 675 ]= 79.94 ;
arr[ 676 ]= 75.21 ;
arr[ 677 ]= 7.8 ;
arr[ 678 ]= 3.9 ;
arr[ 679 ]= 50.34 ;
arr[ 680 ]= 82.76 ;
arr[ 681 ]= 89.76 ;
arr[ 682 ]= 56.86 ;
arr[ 683 ]= 37.62 ;
arr[ 684 ]= 96.75 ;
arr[ 685 ]= 9.71 ;
arr[ 686 ]= 29.06 ;
arr[ 687 ]= 86.77 ;
arr[ 688 ]= 97.23 ;
arr[ 689 ]= 39.11 ;
arr[ 690 ]= 35.63 ;
arr[ 691 ]= 7.86 ;
arr[ 692 ]= 44.91 ;
arr[ 693 ]= 93.71 ;
arr[ 694 ]= 6.72 ;
arr[ 695 ]= 85.0 ;
arr[ 696 ]= 65.87 ;
arr[ 697 ]= 92.85 ;
arr[ 698 ]= 19.27 ;
arr[ 699 ]= 58.82 ;
arr[ 700 ]= 94.99 ;
arr[ 701 ]= 87.24 ;
arr[ 702 ]= 69.66 ;
arr[ 703 ]= 30.13 ;
arr[ 704 ]= 53.61 ;
arr[ 705 ]= 5.78 ;
arr[ 706 ]= 20.47 ;
arr[ 707 ]= 60.07 ;
arr[ 708 ]= 70.49 ;
arr[ 709 ]= 14.58 ;
arr[ 710 ]= 8.85 ;
arr[ 711 ]= 82.88 ;
arr[ 712 ]= 29.36 ;
arr[ 713 ]= 47.28 ;
arr[ 714 ]= 38.95 ;
arr[ 715 ]= 93.15 ;
arr[ 716 ]= 75.89 ;
arr[ 717 ]= 33.02 ;
arr[ 718 ]= 63.0 ;
arr[ 719 ]= 20.82 ;
arr[ 720 ]= 32.77 ;
arr[ 721 ]= 29.22 ;
arr[ 722 ]= 21.37 ;
arr[ 723 ]= 58.45 ;
arr[ 724 ]= 52.48 ;
arr[ 725 ]= 17.33 ;
arr[ 726 ]= 10.07 ;
arr[ 727 ]= 94.68 ;
arr[ 728 ]= 74.77 ;
arr[ 729 ]= 47.98 ;
arr[ 730 ]= 50.81 ;
arr[ 731 ]= 43.35 ;
arr[ 732 ]= 2.0 ;
arr[ 733 ]= 64.53 ;
arr[ 734 ]= 66.48 ;
arr[ 735 ]= 32.9 ;
arr[ 736 ]= 55.3 ;
arr[ 737 ]= 72.83 ;
arr[ 738 ]= 99.12 ;
arr[ 739 ]= 82.4 ;
arr[ 740 ]= 51.37 ;
arr[ 741 ]= 75.19 ;
arr[ 742 ]= 47.61 ;
arr[ 743 ]= 98.11 ;
arr[ 744 ]= 62.22 ;
arr[ 745 ]= 28.09 ;
arr[ 746 ]= 90.27 ;
arr[ 747 ]= 72.8 ;
arr[ 748 ]= 67.98 ;
arr[ 749 ]= 47.23 ;
arr[ 750 ]= 8.35 ;
arr[ 751 ]= 61.32 ;
arr[ 752 ]= 89.37 ;
arr[ 753 ]= 57.24 ;
arr[ 754 ]= 85.87 ;
arr[ 755 ]= 9.37 ;
arr[ 756 ]= 79.32 ;
arr[ 757 ]= 55.46 ;
arr[ 758 ]= 44.1 ;
arr[ 759 ]= 58.62 ;
arr[ 760 ]= 61.68 ;
arr[ 761 ]= 67.61 ;
arr[ 762 ]= 82.29 ;
arr[ 763 ]= 82.69 ;
arr[ 764 ]= 9.29 ;
arr[ 765 ]= 56.53 ;
arr[ 766 ]= 24.31 ;
arr[ 767 ]= 18.7 ;
arr[ 768 ]= 37.12 ;
arr[ 769 ]= 96.58 ;
arr[ 770 ]= 58.46 ;
arr[ 771 ]= 35.27 ;
arr[ 772 ]= 67.58 ;
arr[ 773 ]= 44.58 ;
arr[ 774 ]= 30.3 ;
arr[ 775 ]= 27.7 ;
arr[ 776 ]= 61.55 ;
arr[ 777 ]= 15.39 ;
arr[ 778 ]= 72.71 ;
arr[ 779 ]= 43.12 ;
arr[ 780 ]= 62.07 ;
arr[ 781 ]= 51.55 ;
arr[ 782 ]= 81.54 ;
arr[ 783 ]= 59.36 ;
arr[ 784 ]= 33.9 ;
arr[ 785 ]= 27.08 ;
arr[ 786 ]= 66.16 ;
arr[ 787 ]= 4.79 ;
arr[ 788 ]= 91.46 ;
arr[ 789 ]= 19.58 ;
arr[ 790 ]= 85.93 ;
arr[ 791 ]= 15.57 ;
arr[ 792 ]= 41.56 ;
arr[ 793 ]= 98.27 ;
arr[ 794 ]= 13.35 ;
arr[ 795 ]= 5.41 ;
arr[ 796 ]= 99.4 ;
arr[ 797 ]= 12.81 ;
arr[ 798 ]= 61.81 ;
arr[ 799 ]= 0.05 ;
arr[ 800 ]= 62.62 ;
arr[ 801 ]= 62.55 ;
arr[ 802 ]= 23.29 ;
arr[ 803 ]= 56.37 ;
arr[ 804 ]= 76.5 ;
arr[ 805 ]= 82.65 ;
arr[ 806 ]= 1.33 ;
arr[ 807 ]= 10.38 ;
arr[ 808 ]= 0.81 ;
arr[ 809 ]= 23.21 ;
arr[ 810 ]= 51.25 ;
arr[ 811 ]= 71.84 ;
arr[ 812 ]= 18.85 ;
arr[ 813 ]= 30.62 ;
arr[ 814 ]= 28.67 ;
arr[ 815 ]= 83.18 ;
arr[ 816 ]= 99.33 ;
arr[ 817 ]= 53.19 ;
arr[ 818 ]= 17.21 ;
arr[ 819 ]= 30.83 ;
arr[ 820 ]= 11.97 ;
arr[ 821 ]= 50.82 ;
arr[ 822 ]= 87.11 ;
arr[ 823 ]= 79.25 ;
arr[ 824 ]= 87.68 ;
arr[ 825 ]= 38.96 ;
arr[ 826 ]= 88.59 ;
arr[ 827 ]= 57.05 ;
arr[ 828 ]= 41.54 ;
arr[ 829 ]= 72.49 ;
arr[ 830 ]= 1.77 ;
arr[ 831 ]= 46.33 ;
arr[ 832 ]= 13.19 ;
arr[ 833 ]= 12.12 ;
arr[ 834 ]= 59.86 ;
arr[ 835 ]= 64.74 ;
arr[ 836 ]= 4.41 ;
arr[ 837 ]= 17.09 ;
arr[ 838 ]= 8.71 ;
arr[ 839 ]= 41.92 ;
arr[ 840 ]= 82.95 ;
arr[ 841 ]= 52.97 ;
arr[ 842 ]= 17.58 ;
arr[ 843 ]= 24.77 ;
arr[ 844 ]= 86.96 ;
arr[ 845 ]= 74.18 ;
arr[ 846 ]= 63.93 ;
arr[ 847 ]= 84.94 ;
arr[ 848 ]= 12.66 ;
arr[ 849 ]= 93.58 ;
arr[ 850 ]= 50.14 ;
arr[ 851 ]= 1.66 ;
arr[ 852 ]= 96.61 ;
arr[ 853 ]= 12.99 ;
arr[ 854 ]= 71.16 ;
arr[ 855 ]= 15.88 ;
arr[ 856 ]= 78.18 ;
arr[ 857 ]= 39.47 ;
arr[ 858 ]= 98.05 ;
arr[ 859 ]= 9.89 ;
arr[ 860 ]= 86.29 ;
arr[ 861 ]= 33.92 ;
arr[ 862 ]= 93.04 ;
arr[ 863 ]= 58.58 ;
arr[ 864 ]= 47.01 ;
arr[ 865 ]= 22.22 ;
arr[ 866 ]= 36.09 ;
arr[ 867 ]= 43.49 ;
arr[ 868 ]= 77.84 ;
arr[ 869 ]= 10.89 ;
arr[ 870 ]= 93.62 ;
arr[ 871 ]= 99.98 ;
arr[ 872 ]= 83.03 ;
arr[ 873 ]= 48.07 ;
arr[ 874 ]= 81.63 ;
arr[ 875 ]= 72.73 ;
arr[ 876 ]= 8.65 ;
arr[ 877 ]= 16.47 ;
arr[ 878 ]= 74.37 ;
arr[ 879 ]= 27.56 ;
arr[ 880 ]= 89.41 ;
arr[ 881 ]= 3.61 ;
arr[ 882 ]= 42.03 ;
arr[ 883 ]= 20.04 ;
arr[ 884 ]= 40.06 ;
arr[ 885 ]= 32.46 ;
arr[ 886 ]= 54.75 ;
arr[ 887 ]= 2.75 ;
arr[ 888 ]= 17.16 ;
arr[ 889 ]= 52.5 ;
arr[ 890 ]= 73.35 ;
arr[ 891 ]= 5.08 ;
arr[ 892 ]= 2.32 ;
arr[ 893 ]= 50.92 ;
arr[ 894 ]= 62.54 ;
arr[ 895 ]= 2.08 ;
arr[ 896 ]= 2.55 ;
arr[ 897 ]= 16.48 ;
arr[ 898 ]= 83.82 ;
arr[ 899 ]= 43.68 ;
arr[ 900 ]= 75.03 ;
arr[ 901 ]= 7.0 ;
arr[ 902 ]= 93.6 ;
arr[ 903 ]= 42.0 ;
arr[ 904 ]= 90.33 ;
arr[ 905 ]= 62.97 ;
arr[ 906 ]= 58.27 ;
arr[ 907 ]= 88.55 ;
arr[ 908 ]= 63.5 ;
arr[ 909 ]= 4.68 ;
arr[ 910 ]= 26.08 ;
arr[ 911 ]= 11.49 ;
arr[ 912 ]= 48.62 ;
arr[ 913 ]= 21.26 ;
arr[ 914 ]= 34.61 ;
arr[ 915 ]= 89.87 ;
arr[ 916 ]= 34.47 ;
arr[ 917 ]= 49.4 ;
arr[ 918 ]= 4.47 ;
arr[ 919 ]= 80.14 ;
arr[ 920 ]= 59.33 ;
arr[ 921 ]= 91.17 ;
arr[ 922 ]= 13.43 ;
arr[ 923 ]= 80.65 ;
arr[ 924 ]= 78.88 ;
arr[ 925 ]= 13.66 ;
arr[ 926 ]= 61.16 ;
arr[ 927 ]= 45.26 ;
arr[ 928 ]= 39.54 ;
arr[ 929 ]= 68.57 ;
arr[ 930 ]= 66.97 ;
arr[ 931 ]= 84.05 ;
arr[ 932 ]= 17.29 ;
arr[ 933 ]= 94.05 ;
arr[ 934 ]= 33.19 ;
arr[ 935 ]= 92.45 ;
arr[ 936 ]= 1.58 ;
arr[ 937 ]= 18.39 ;
arr[ 938 ]= 50.84 ;
arr[ 939 ]= 32.32 ;
arr[ 940 ]= 48.54 ;
arr[ 941 ]= 24.86 ;
arr[ 942 ]= 10.2 ;
arr[ 943 ]= 27.07 ;
arr[ 944 ]= 68.71 ;
arr[ 945 ]= 47.99 ;
arr[ 946 ]= 35.53 ;
arr[ 947 ]= 41.8 ;
arr[ 948 ]= 76.68 ;
arr[ 949 ]= 20.36 ;
arr[ 950 ]= 3.71 ;
arr[ 951 ]= 6.74 ;
arr[ 952 ]= 54.41 ;
arr[ 953 ]= 40.79 ;
arr[ 954 ]= 96.45 ;
arr[ 955 ]= 13.99 ;
arr[ 956 ]= 41.91 ;
arr[ 957 ]= 61.33 ;
arr[ 958 ]= 2.23 ;
arr[ 959 ]= 89.04 ;
arr[ 960 ]= 76.69 ;
arr[ 961 ]= 13.97 ;
arr[ 962 ]= 21.44 ;
arr[ 963 ]= 5.69 ;
arr[ 964 ]= 82.92 ;
arr[ 965 ]= 95.98 ;
arr[ 966 ]= 33.09 ;
arr[ 967 ]= 37.84 ;
arr[ 968 ]= 29.74 ;
arr[ 969 ]= 53.66 ;
arr[ 970 ]= 53.07 ;
arr[ 971 ]= 30.14 ;
arr[ 972 ]= 37.37 ;
arr[ 973 ]= 23.57 ;
arr[ 974 ]= 72.34 ;
arr[ 975 ]= 70.51 ;
arr[ 976 ]= 49.15 ;
arr[ 977 ]= 8.13 ;
arr[ 978 ]= 62.49 ;
arr[ 979 ]= 96.73 ;
arr[ 980 ]= 92.19 ;
arr[ 981 ]= 36.83 ;
arr[ 982 ]= 55.11 ;
arr[ 983 ]= 72.53 ;
arr[ 984 ]= 24.49 ;
arr[ 985 ]= 57.52 ;
arr[ 986 ]= 4.5 ;
arr[ 987 ]= 43.16 ;
arr[ 988 ]= 63.67 ;
arr[ 989 ]= 59.98 ;
arr[ 990 ]= 59.39 ;
arr[ 991 ]= 60.15 ;
arr[ 992 ]= 13.68 ;
arr[ 993 ]= 24.0 ;
arr[ 994 ]= 37.64 ;
arr[ 995 ]= 65.85 ;
arr[ 996 ]= 10.51 ;
arr[ 997 ]= 35.55 ;
arr[ 998 ]= 75.13 ;
arr[ 999 ]= 82.19 ;
arr[ 1000 ]= 38.97 ;
arr[ 1001 ]= 29.59 ;
arr[ 1002 ]= 41.52 ;
arr[ 1003 ]= 73.32 ;
arr[ 1004 ]= 5.98 ;
arr[ 1005 ]= 52.59 ;
arr[ 1006 ]= 62.16 ;
arr[ 1007 ]= 0.28 ;
arr[ 1008 ]= 13.14 ;
arr[ 1009 ]= 4.18 ;
arr[ 1010 ]= 79.2 ;
arr[ 1011 ]= 19.76 ;
arr[ 1012 ]= 35.89 ;
arr[ 1013 ]= 68.1 ;
arr[ 1014 ]= 30.31 ;
arr[ 1015 ]= 75.91 ;
arr[ 1016 ]= 49.24 ;
arr[ 1017 ]= 93.87 ;
arr[ 1018 ]= 37.8 ;
arr[ 1019 ]= 90.72 ;
arr[ 1020 ]= 6.89 ;
arr[ 1021 ]= 85.65 ;
arr[ 1022 ]= 26.24 ;
arr[ 1023 ]= 61.58 ;
arr[ 1024 ]= 74.4 ;
arr[ 1025 ]= 55.1 ;
arr[ 1026 ]= 75.14 ;
arr[ 1027 ]= 61.23 ;
arr[ 1028 ]= 8.84 ;
arr[ 1029 ]= 15.5 ;
arr[ 1030 ]= 7.5 ;
arr[ 1031 ]= 22.55 ;
arr[ 1032 ]= 70.09 ;
arr[ 1033 ]= 62.84 ;
arr[ 1034 ]= 58.18 ;
arr[ 1035 ]= 34.38 ;
arr[ 1036 ]= 7.81 ;
arr[ 1037 ]= 31.96 ;
arr[ 1038 ]= 3.85 ;
arr[ 1039 ]= 46.6 ;
arr[ 1040 ]= 90.13 ;
arr[ 1041 ]= 82.0 ;
arr[ 1042 ]= 32.38 ;
arr[ 1043 ]= 18.48 ;
arr[ 1044 ]= 92.03 ;
arr[ 1045 ]= 9.82 ;
arr[ 1046 ]= 75.99 ;
arr[ 1047 ]= 20.95 ;
arr[ 1048 ]= 33.59 ;
arr[ 1049 ]= 57.26 ;
arr[ 1050 ]= 72.26 ;
arr[ 1051 ]= 33.12 ;
arr[ 1052 ]= 14.52 ;
arr[ 1053 ]= 24.11 ;
arr[ 1054 ]= 32.98 ;
arr[ 1055 ]= 73.06 ;
arr[ 1056 ]= 16.03 ;
arr[ 1057 ]= 95.92 ;
arr[ 1058 ]= 85.52 ;
arr[ 1059 ]= 52.93 ;
arr[ 1060 ]= 94.37 ;
arr[ 1061 ]= 85.43 ;
arr[ 1062 ]= 75.61 ;
arr[ 1063 ]= 15.72 ;
arr[ 1064 ]= 74.95 ;
arr[ 1065 ]= 20.19 ;
arr[ 1066 ]= 73.37 ;
arr[ 1067 ]= 56.41 ;
arr[ 1068 ]= 0.99 ;
arr[ 1069 ]= 28.4 ;
arr[ 1070 ]= 13.77 ;
arr[ 1071 ]= 82.98 ;
arr[ 1072 ]= 89.82 ;
arr[ 1073 ]= 45.15 ;
arr[ 1074 ]= 54.24 ;
arr[ 1075 ]= 68.9 ;
arr[ 1076 ]= 50.52 ;
arr[ 1077 ]= 56.01 ;
arr[ 1078 ]= 93.48 ;
arr[ 1079 ]= 6.6 ;
arr[ 1080 ]= 86.97 ;
arr[ 1081 ]= 4.35 ;
arr[ 1082 ]= 47.73 ;
arr[ 1083 ]= 82.38 ;
arr[ 1084 ]= 79.88 ;
arr[ 1085 ]= 91.19 ;
arr[ 1086 ]= 8.48 ;
arr[ 1087 ]= 18.59 ;
arr[ 1088 ]= 57.53 ;
arr[ 1089 ]= 1.35 ;
arr[ 1090 ]= 34.29 ;
arr[ 1091 ]= 75.63 ;
arr[ 1092 ]= 43.17 ;
arr[ 1093 ]= 63.01 ;
arr[ 1094 ]= 87.96 ;
arr[ 1095 ]= 98.47 ;
arr[ 1096 ]= 26.62 ;
arr[ 1097 ]= 68.33 ;
arr[ 1098 ]= 89.0 ;
arr[ 1099 ]= 13.42 ;
arr[ 1100 ]= 45.04 ;
arr[ 1101 ]= 69.74 ;
arr[ 1102 ]= 54.31 ;
arr[ 1103 ]= 66.29 ;
arr[ 1104 ]= 66.66 ;
arr[ 1105 ]= 89.16 ;
arr[ 1106 ]= 26.05 ;
arr[ 1107 ]= 37.77 ;
arr[ 1108 ]= 50.89 ;
arr[ 1109 ]= 8.81 ;
arr[ 1110 ]= 21.95 ;
arr[ 1111 ]= 95.07 ;
arr[ 1112 ]= 36.24 ;
arr[ 1113 ]= 79.68 ;
arr[ 1114 ]= 34.12 ;
arr[ 1115 ]= 19.88 ;
arr[ 1116 ]= 87.65 ;
arr[ 1117 ]= 35.25 ;
arr[ 1118 ]= 2.02 ;
arr[ 1119 ]= 12.05 ;
arr[ 1120 ]= 3.64 ;
arr[ 1121 ]= 71.96 ;
arr[ 1122 ]= 58.56 ;
arr[ 1123 ]= 30.6 ;
arr[ 1124 ]= 85.79 ;
arr[ 1125 ]= 47.32 ;
arr[ 1126 ]= 20.54 ;
arr[ 1127 ]= 84.85 ;
arr[ 1128 ]= 36.23 ;
arr[ 1129 ]= 68.88 ;
arr[ 1130 ]= 55.01 ;
arr[ 1131 ]= 37.46 ;
arr[ 1132 ]= 80.99 ;
arr[ 1133 ]= 96.57 ;
arr[ 1134 ]= 17.03 ;
arr[ 1135 ]= 22.64 ;
arr[ 1136 ]= 95.57 ;
arr[ 1137 ]= 11.57 ;
arr[ 1138 ]= 50.64 ;
arr[ 1139 ]= 50.1 ;
arr[ 1140 ]= 0.12 ;
arr[ 1141 ]= 68.32 ;
arr[ 1142 ]= 85.32 ;
arr[ 1143 ]= 17.98 ;
arr[ 1144 ]= 66.55 ;
arr[ 1145 ]= 97.82 ;
arr[ 1146 ]= 49.74 ;
arr[ 1147 ]= 43.24 ;
arr[ 1148 ]= 34.56 ;
arr[ 1149 ]= 39.66 ;
arr[ 1150 ]= 96.47 ;
arr[ 1151 ]= 37.1 ;
arr[ 1152 ]= 53.64 ;
arr[ 1153 ]= 93.95 ;
arr[ 1154 ]= 57.98 ;
arr[ 1155 ]= 16.55 ;
arr[ 1156 ]= 46.32 ;
arr[ 1157 ]= 60.02 ;
arr[ 1158 ]= 97.7 ;
arr[ 1159 ]= 52.15 ;
arr[ 1160 ]= 5.67 ;
arr[ 1161 ]= 29.53 ;
arr[ 1162 ]= 31.07 ;
arr[ 1163 ]= 41.16 ;
arr[ 1164 ]= 80.66 ;
arr[ 1165 ]= 6.62 ;
arr[ 1166 ]= 29.39 ;
arr[ 1167 ]= 99.9 ;
arr[ 1168 ]= 82.21 ;
arr[ 1169 ]= 92.24 ;
arr[ 1170 ]= 46.52 ;
arr[ 1171 ]= 38.98 ;
arr[ 1172 ]= 50.22 ;
arr[ 1173 ]= 13.76 ;
arr[ 1174 ]= 61.96 ;
arr[ 1175 ]= 46.87 ;
arr[ 1176 ]= 21.89 ;
arr[ 1177 ]= 54.66 ;
arr[ 1178 ]= 59.27 ;
arr[ 1179 ]= 20.9 ;
arr[ 1180 ]= 29.98 ;
arr[ 1181 ]= 34.18 ;
arr[ 1182 ]= 72.01 ;
arr[ 1183 ]= 73.99 ;

 }
