
# 만약 배열이 비었고, 타겟이 영이면 답은 하나, 그렇지 않으면 답은 영
# 만약 배열이 존재하면 재귀적으로 솔루션 함수를 반복할 것
# 첫번째 배열 값을 제외하고, 타겟에 첫번째 배열을 더한 한 솔루션과 첫번째 밸열값 제외하고 타겟에 첫번째 배열을 뺀 솔루션값을 더한 걸 리턴 

def solution(numbers, target):
    if numbers == []:
        if target == 0:
            return 1
        else:
            return 0
    else:
        return solution(numbers[1:], target+numbers[0]) + solution(numbers[1:], target-numbers[0])