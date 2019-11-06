# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int idCount = 0;

struct client {
	char name[10];
	char phoneNum[15];
	int id;
};

// 사용자 추가 함수
void add(struct client list[], int* index) {
	struct client temp;

	printf("이름을 입력해주세요. \n");
	scanf("%s", temp.name);
	printf("전화번호를 입력해주세요. \n");
	scanf("%s", temp.phoneNum);
	temp.id = idCount++;

	list[(*index)++] = temp;
	printf("이름 : %s, 전화번호 : %s, ID : %d \n", temp.name, temp.phoneNum, temp.id);
}

// 사용자 제거 함수
void delete(struct client list[], int* index) {
	int select, delID, deleteMode = 0;
	char delName[10], delPhoneNum[15];

	printf("입력할 정보를 선택해주세요. \n");
	printf("1. 이름 \n");
	printf("2. 전화번호 \n");
	printf("3. 고유 ID \n");
	scanf("%d", &select);

    // 이름으로 제거
	if (select == 1) {
		printf("이름을 입력해주세요. \n");
		scanf("%s", delName);
		do {
			deleteMode = 0;
			for (int i = 0; i < *index; i++){
				if(strcmp(delName, list[i].name) == 0 || deleteMode == 1) {
					deleteMode = 1;
					list[i] = list[i + 1];
                }
			}
            if(deleteMode != 0){
                *index -= 1;
            }
        }while(deleteMode != 0);
	}
    
    // 전화번호로 제거
	else if (select == 2) {
		printf("전화번호를 입력해주세요. \n");
		scanf("%s", delPhoneNum);
		for (int i = 0; i < *index; i++) {
			if (strcmp(delPhoneNum, list[i].phoneNum) == 0 || deleteMode == 1) {
				deleteMode = 1;
				list[i] = list[i + 1];
			}
		}
        if(deleteMode == 1){
            *index -= 1;
        }
	}
    
    // 고유 ID로 제거
	else if (select == 3) {
		printf("고유 ID를 입력해주세요. \n");
		scanf("%d", &delID);
		for (int i = 0; i < *index; i++) {
			if (delID == list[i].id || deleteMode == 1) {
				deleteMode = 1;
				list[i] = list[i + 1];
			}
		}
        if(deleteMode == 1){
            *index -= 1;
        }
	}
    
	else {
		printf("잘못된 입력입니다.\n");
	}
}

// 사용자 검색 함수
void find(struct client list[], int index) {
	int select, selection, getID;
	char getName[10], getPhoneNum[15];

	printf("검색할 항목을 선택해주세요 (1. 전체검색, 2. 항목검색) \n");
	scanf("%d", &select);

    // 전체검색(전체출력)
	if (select == 1) {
		for (int i = 0; i < index; i++) {
			printf("이름 : %s, 전화번호 : %s, ID : %d \n", list[i].name, list[i].phoneNum, list[i].id);
		}
	}
    
    // 항목 검색
	else if (select == 2) {
		printf("입력할 항목을 선택해주세요. (1. 이름, 2. 전화번호, 3. 고유 ID) \n");
		scanf("%d", &selection);
        
        // 이름으로 검색
		if (selection == 1) {
			printf("이름을 입력해주세요. \n");
			scanf("%s", getName);
			for (int i = 0; i < index; i++) {
				if (strcmp(getName, list[i].name) == 0) {
					printf("이름 : %s, 전화번호 : %s, ID : %d \n", list[i].name, list[i].phoneNum, list[i].id);
				}
			}
		}
        
        // 전화 번호로 검색
		else if (selection == 2) {
			printf("전화번호를 입력해주세요. \n");
			scanf("%s", getPhoneNum);
			for (int i = 0; i < index; i++) {
				if (strcmp(getPhoneNum, list[i].phoneNum) == 0) {
					printf("이름 : %s, 전화번호 : %s, ID : %d \n", list[i].name, list[i].phoneNum, list[i].id);
				}
			}
		}
        
        // 고유 ID로 검색
		else if (selection == 3) {
			printf("고유 ID를 입력해주세요. \n");
			scanf("%d", &getID);
			for (int i = 0; i < index; i++) {
				if (getID == list[i].id) {
					printf("이름 : %s, 전화번호 : %s, ID : %d \n", list[i].name, list[i].phoneNum, list[i].id);
				}
			}
		}
		else{
			printf("잘못된 입력입니다. \n");
		}
	}
	else {
		printf("잘못된 입력입니다. \n");
	}
}

int main() {
	int getNum, index = 0;
	struct client list[500];
	while (1) {
		printf("1. 사용자 추가 \n");
		printf("2. 사용자 제거 \n");
		printf("3. 사용자 검색 \n");
		scanf("%d", &getNum);

		switch (getNum) {
			case 1 :
				add(list,&index);
				break;
			case 2 :
				delete(list, &index);
				break;
			case 3 :
				find(list, index);
				break;
			case -1 :
				return 0;

			default :
				printf("잘못된 입력입니다. \n");
		}
	}
}
