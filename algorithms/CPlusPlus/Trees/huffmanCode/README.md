# Huffman Code

## Goal

The goal is minimize the size of files using the fact that some characters are redundant and with higher frequency than others like the word the, so the goal is to use less chars to type the most common words and more chars for the least common words.

## Get Started

In the `main.cpp` file you can find a running example and the results can be seen in details phase by phase in the results folder

## The trick

The problem with this Huffman codes is that it uses the Concept of **make the common case faster** regrading the frequency of words in the file which is a variable of the file itself.
So for better performance the program records the frequency of each word in the file before processing, providing the algorithm with the best prediction.

## performance

This algorithms here decrease the files size to half on average.
personally, I used it in this program to minimize my xml and json files.

## Application

Mainly this algorithm is used to decrease files size from text to audio.
