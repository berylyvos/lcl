package main

import (
	"fmt"
	"sort"
)

func merge(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	res := [][]int{}
	l, r := intervals[0][0], intervals[0][1]

	for i := 1; i < len(intervals); i++ {
		cur := intervals[i]
		if intervals[i][0] <= r {
			r = max(r, cur[1])
		} else {
			res = append(res, []int{l, r})
			l, r = cur[0], cur[1]
		}
	}

	res = append(res, []int{l, r})

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	intervals := [][]int{{1, 3}, {2, 6}, {8, 10}, {15, 18}}
	fmt.Println(merge(intervals))
}
