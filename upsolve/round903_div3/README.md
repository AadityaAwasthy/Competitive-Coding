# Div 3 - Round 903

## Problem F - Minimum Maximum Distance

### TLDR

Find the maximum distance between two marked nodes , answer will be half of that distance

- You will always find the max distance between two marked nodes in a tree if you go from any marked vertex to the most distant vertex then did the same from that vertex , the second distance will be the answer

### Description

Find the farthest marked node from any marked node , this will take you to one of the extreme marked nodes in the graph , doing the same procedure from there you will get to the other end of the extreme marked nodes , Only nodes that are between these nodes matter other nodes are irrelevant . 	
