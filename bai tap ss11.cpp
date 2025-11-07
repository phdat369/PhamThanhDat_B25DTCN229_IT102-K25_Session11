#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[100];
	int n = 0;
	int choice;
	char confirm = 'Y';
	int sorted = 0;
	
	while(confirm == 'Y' || confirm == 'y' ){
		printf("\n=====================MENU=====================\n");
		printf("1. Nhap mang\n");
		printf("2. In mang\n");	
		printf("3. tinh Tong va trung binh cong\n");
		printf("4. Sap xep mang\n");
		printf("5. Tim kiem phan tu trong mang\n");	
		printf("6. Xoa phan tu\n");
		printf("7. chen phan tu vao mang\n");
		printf("8. Xoa cac phan tu theo gia tri\n");
		printf("9. Thoat.\n");
		printf("1. ==============================================\n");
		printf("Moi ban nhap lua chon: \n");
		scanf("%d",&choice);
		
		switch (choice){
			case 1:{
				printf("nhap so phan tu n:");
				scanf("%d",&n);
				if(n <= 0 || n > 100){
					printf("so phan tu khong hop le \n");
					n = 0;
					break;
				}
				printf("\n");
				for(int i = 0; i < n;i++){
					printf("arr[%d] = ",i);
					scanf("%d",&arr[i]);
				}
				sorted = 0;
				break;
			}
			case 2:{
				if(n == 0){
					printf("mang rong\n");
				}
				printf("mang hien tai: ");
				for(int i = 0; i < n;i++){
					printf("arr[%d] = %d\n",i,arr[i]);
				}
				break;
			}
			case 3:{
				if(n == 0){
					printf("mang rong");
					break;
				}
				int sum = 0;
				for(int i = 0; i < n;i++){
					sum += arr[i];
				}
				printf("tong = %d, trung binh cong = %.2f \n",sum, (float)sum / n);
				break;
			}
			case 4:{
				if(n == 0){
					printf("mang rong");
					break;
				}
				char type;
				printf("a. Bubble Sort (increase)\n");
				printf("b. Selection  Sort (decrease)\n");
				printf("c. Insertion  Sort (increase)\n");
				printf("moi chon kieu sap xep: ");
				scanf(" %c",&type);
				switch(type){
					case 'a':{
						for(int i = 0;i < n - 1;i++){
							for(int j = 0; j < n - i - 1;j++){
								if(arr[j] > arr[j+1]){
									int temp = arr[j];
									arr[j] = arr[j+1];
									arr[j+1]= temp;
								}
							}
						}
						printf("mang da duoc sap xep ( bubble sort ) \n");
						sorted = 1;
						break;
					}
					case 'b':{
						for(int i = 0; i < n - 1;i++){
							int maxIndex = i;
							for(int j = i + 1;j < n;j++){
								if(arr[j] > arr[maxIndex]){
									maxIndex = j;
								}
							}
							int temp = arr[i];
							arr[i] = arr[maxIndex];
							arr[maxIndex] = temp;
						}
						printf("mang da duoc sap xep ( selection sort ) \n");
						sorted = 1;
						break;
					}
					case 'c':{
						for(int i = 1;i < n;i++){
							int key = arr[i];
							int j = i -1;
							while(j >= 0 && arr[j] > key){
								arr[j + 1] = arr[j];
								j--;
							}
							arr[j + 1] = key;
						}
						printf("mang da duoc sap xep ( insertion sort ) \n");
						sorted = 1;
						break;
					}
					default:
						printf("lua chon k hop le");
						
				
				}
				printf("mang sau sap xep: \n");
					for(int i = 0; i < n;i++){
					printf("arr[%d] = %d\n",i,arr[i]);
					}
					printf("\n");
				break;
			}
			case 5:{
				if(n == 0){
					printf("mang rong");
					break;
				}
				
				int x,pos = -1;
				printf("nhap vao gia tri can tim: ");
				scanf("%d",&x);
				
			
				if(sorted == 0){
					for(int i = 0 ; i < n;i++){
						if(arr[i] == x){
							pos = i;
							break;
						}
					}
				}else{ 
					int left = 0,right = n -1;
					while(left <= right){
						int mid = (left + right) / 2;
						if(arr[mid] == x){
							pos = mid;
							break;
						}
						if(arr[mid] < x){
							left =mid + 1; 	
						}else{
							right = mid - 1;
						}
					}
				}
				if(pos == -1 ){
					printf("khong tim thay %d trong mang\n");
				}else{
					printf("Tim thay %d tai vi tri %d\n",x,pos);
				}
				break;
			}
			case 6:{
				if(n == 0){
					printf("mang rong\n");
					break;
				}
				
				int index;
				printf("vi tri can xoa: ");
				scanf("%d",&index);
				if(index < 0 || index >= n){
					printf("chi so khong hop le!!! \n");
					break;
				}
				for(int i = index;i < n -1;i++){
					arr[i] = arr[i+1];
				}
				n--;
				printf("da xoa phan tu tai chi so %d \n",index);
				break;
			}
			case 7:{
				if(n >= 100){
					printf("mang da day!!");
					break;
				}
				
				int index,value;
				printf("nhap chi so can chen: ");
				scanf("%d",&index );
				printf("nhap gia tri can chen: ");
				scanf("%d",&value);
				if(index < 0 || index > n){
					printf("chi so khong hop le!!! \n");
					break;
				}
				for(int i = n; i > index;i--){
					arr[i] = arr[i-1];
				}
				arr[index] = value;
				n++;
				printf("da chen phan tu %d vao chi so %d \n",value,index);
				
				break;
			}
			case 8:{
				if(n == 0){
					printf("mang rong");
					break;
				}
				int value, count=0;

				printf("nhap gia tri can xoa: ");
				scanf("%d",&value);
				
				for(int i =0; i < n;i++){
					if(arr[i] == value){
					for(int j = i;j < n -1;j++){
						arr[j] = arr[j+1];
					}
					n--;
					i--;
					count++;
					}
				}
				if(count == 0){
					printf("Khong co phan tu nao co gia tri %d\n",value);
				}else{
					printf("da xoa %d phan co gia tri %d\n",count,value);
				}
				break;
			}
			case 9:{
				printf("Cam on vi da den!!!");
				return 0;
			}
			default:{
				printf("Lua chon khong hop le\n");
				break;
			}
		}
		printf("Ban co muon nhap tiep khong (Y/N)?: ");
		scanf(" %c",&confirm);
		
	}
	
}
