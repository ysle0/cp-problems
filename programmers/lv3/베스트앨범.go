// https://school.programmers.co.kr/learn/courses/30/lessons/42579
import "sort"

type record struct {
	count int
	unq   []unq
}

type unq struct {
	index int
	plays int
}

func solution(genres []string, plays []int) []int {
	rank := map[string]record{}
	buf := []record{}
	for i := 0; i < len(genres); i++ {
		if _, ok := rank[genres[i]]; !ok {
			rank[genres[i]] = record{
				count: plays[i],
				unq:   []unq{{i, plays[i]}},
			}
		} else {
			r := rank[genres[i]]
			rank[genres[i]] = record{
				count: r.count + plays[i],
				unq:   append(r.unq, unq{i, plays[i]}),
			}
		}
	}

	for _, r := range rank {
		buf = append(buf, r)
		sort.Slice(
			r.unq,
			func(i, j int) bool { return r.unq[i].plays > r.unq[j].plays },
		)
	}
	sort.Slice(
		buf,
		func(i, j int) bool { return buf[i].count > buf[j].count },
	)

	var ret []int
	for _, b := range buf {
		l := len(b.unq)
		if l == 0 {
			continue
		}
		slice := b.unq[:l]
		for _, s := range slice {
			ret = append(ret, s.index)
		}
		b.unq = b.unq[l:]
	}
	return ret
}