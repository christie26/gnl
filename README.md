# get_next_line

### 각 함수의 역할 정리

1. `ft_read_buffer`
    1. **역할** `BUFFER_SIZE` 크기만큼 읽어 `buf` 라는 변수에 저장한다. 
    2. **while** `sto` 에 `\n` 이 들어있으면 탈출
2. `ft_get_line`
    1. 완성된 `storage` 를 가지고, 출력할 부분`line`과 `storage` 에 남길 부분을 구분한다. 
3. `ft_free`
    1. 배열의 주소값을 인자로 받아 `free` 후 0로 초기화 한다. 

### 어려웠던 점
1. 각 예외 처리 상황에서, `free` 해야 하는 것 구분하기 (`buf`, `storage`, `tmp`)
2. `storage` 는 static 변수로서 
    1. `buffer`에서 출력된 부분을 제외하고 저장해두어야 한다.
    2. 오류가 난 경우에는 0으로 초기화가 되어 있어야 한다.
