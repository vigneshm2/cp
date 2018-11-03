//
//  segment_tree_lazy.cpp
//  segmenttree
//
//  Created by Vignesh M on 07/02/15.
//  Copyright (c) 2015 vignesh. All rights reserved.
//
//  http://www.spoj.com/problems/POSTERS/

#include <stdio.h>
const int MAXN=40010;
int arr[MAXN];
int tree[4*MAXN];
int n;
void build(int root=1,int l=0,int r=n){
    if(l-r<2){
        tree[root]=arr[l];
    }
    
}