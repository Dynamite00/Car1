#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 자동차 상태, 구조체 정의
typedef struct {
    char make[50];   // 제조사
    char model[50];  // 모델
    float speed;     // 현재 속도 (km/h)
    float fuel;      // 연료량 (리터)
    float distance;  // 주행 거리 (km)
} Car;

// 자동차 초기화 함수
void initializeCar(Car* car, const char* make, const char* model) {
    strcpy(car->make, make);      // strcpy  ->  <string.h> 헤더 파일 추가
    strcpy(car->model, model);
    car->speed = 0;
    car->fuel = 50;  // 초기 연료량 설정
    car->distance = 0;
}

// 가속 함수
void accelerate(Car* car, float acceleration) {
    car->speed += acceleration;
}

// 감속 함수
void decelerate(Car* car, float deceleration) {
    car->speed -= deceleration;
    if (car->speed < 0) {
        car->speed = 0;
    }
}

// 주행 함수
void drive(Car* car, float time) {
    car->distance += car->speed * (time / 60);  // 분 단위로 계산
    car->fuel -= 0.1 * (car->speed / 10) * (time / 60);  // 연료 소비량 시뮬레이션
    if (car->fuel < 0) {
        car->fuel = 0;
    }
}

// 정지 함수
void stop(Car* car) {
    car->speed = 0;
}

// 상태 표시 함수
void displayStatus(const Car* car) {
    printf("\n----- 상태 표시 -----\n");
    printf("차량: %s %s\n", car->make, car->model);
    printf("현재 속도: %.2f km/h\n", car->speed);
    printf("주행 거리: %.2f km\n", car->distance);
    printf("남은 연료량: %.2f 리터\n", car->fuel);
}

int main() {
    Car myCar;
    initializeCar(&myCar, "Hyundai", "Avante");

    printf("자동차 시뮬레이션을 시작합니다.\n");

    int option;
    float value;
    while (1) {                                      // 입력 메뉴
        printf("\n\n메뉴를 선택하세요:\n\n");
        printf("1. 가속\n");
        printf("2. 감속\n");
        printf("3. 주행\n");
        printf("4. 정지\n");
        printf("5. 상태 표시\n");
        printf("6. 종료\n\n");
        scanf_s("%d", &option);

        switch (option) {
        case 1:
            printf("\n가속할 양을 입력하세요 (km/h): ");
            scanf_s("%f", &value);                        // scanf 로 작성 시 보안 취약 사유로 에러 발생 scanf_s 로 수정 하거나 맨 위 #define _CRT_SECURE_NO_WARNINGS 전처리기 추가
            accelerate(&myCar, value);
            break;
        case 2:
            printf("\n감속할 양을 입력하세요 (km/h): ");
            scanf_s("%f", &value);
            decelerate(&myCar, value);
            break;
        case 3:
            printf("\n주행할 시간을 입력하세요 (분): ");
            scanf_s("%f", &value);
            drive(&myCar, value);
            break;
        case 4:
            stop(&myCar);
            break;
        case 5:
            displayStatus(&myCar);
            break;
        case 6:
            printf("\n프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("\n잘못된 메뉴를 선택하셨습니다.\n");
            break;
        }
    }

    return 0;
}
