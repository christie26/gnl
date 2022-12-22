# gnl

### 각 함수의 역할 정리

1. `ft_read_buffer`
    1. **역할** `BUFFER_SIZE` 크기만큼 읽어 `buf` 라는 변수에 저장
    2. **while** `sto` 에 `\n` 이 들어있으면 탈출
2. `ft_get_line`
    1. 완성된 `storage` 를 가지고, 출력할 부분`line`과 `storage` 에 남길 부분을 구분한다. 
3. `ft_free`
