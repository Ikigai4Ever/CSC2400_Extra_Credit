# CSC2400_Extra_Credit

## Explanation of Project

My design uses the C++ programming language to take in a user input of numbers that are defined by dynamically allocating an array once the user states how large they would like to make the array. 


## Project Goal Outline & Description:

    // Input: A sequence S with n elements
    // Output: The maximium element in S

    if n = 1 then
        retun S[0]

    else 
        maxRest <- RecursiveMaxFind(S, n-1) 

        if maxRest > S[n-1] then 
            return maxRest
        else 
            return S[n-1] 

### Requirements For Project

1. Fully exectuable program 
2. Uses a recursive [1], decrease-by-one [2] and conquer [3] approach
3. Accept input parameters from a user

**Required Input**: S = [3,5,2,9,1,8,0,2] 

note**: this is a parameter and not hardcoded

## Citations: 

“I want to take in a set of numbers like this: 3, 5, 2, 9, 1, 8, 0, 2 and make sure to read only the numbers from the string.” prompt. ChatGPT, 13 Feb. version 4.0, OpenAI, 29 Apr. 2025, chat.openai.com/chat.