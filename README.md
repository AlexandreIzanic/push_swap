*This project has been created as part of the 42 curriculum by aizanic.*

# Push_swap

## Description
The objective is to sort a stack of data using a limited set of instructions with the minimum of operations possible. This project serves as a practical introduction to algorithmic complexity and data structure optimization.

I chose the Radix sort for its predictable bitwise logic, while Turk relies on complex cost-analysis for every move.

Sort algo
- Turk Algo
    - push to stack b until 3 nodes left in a 
    - during each push b is sorted in descending order 
    - every 'a' nodes need a target node from stack 'b'
        - if no closest smaller  number found, target is the max value  
    - Cost analysis 
        - find the cheapest node to push 
- Radix sort
    - sort from each unity

## Instructions

- $>ARGS=$(shuf -i0-9 -n5)
- $>echo $ARGS
- ./push_swap $ARGS | ./checker_OS $ARGS

## Resources

- [Turk algo](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [Radix Sort](https://youtu.be/Y95a-8oNqps?si=rEbA4ihKvo3Uc15X)

### AI Usage Declaration

AI tools were used in the following aspects of this project:
- **Documentation:** Assistance in structuring and formatting this README
- **Research:** Understanding concepts and comparing technologies
