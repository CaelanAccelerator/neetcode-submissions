class Twitter:
    def __init__(self):
        self.time = 0
        self.followMap = defaultdict(set)
        self.tweetMap = defaultdict(list[tuple])
        self.seq = 0
    
    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweetMap[userId].append((tweetId, self.seq))
        self.seq+=1
        

    def getNewsFeed(self, userId: int) -> List[int]:
        pq = []
        for v in self.followMap[userId]:
            for i in range(len(self.tweetMap[v]) - 1, len(self.tweetMap[v]) - 11 if len(self.tweetMap[v]) > 11 else -1, -1):
                heapq.heappush(pq ,(-self.tweetMap[v][i][1],self.tweetMap[v][i][0]))
        print(self.tweetMap[userId])
        for i in range(len(self.tweetMap[userId]) - 1, len(self.tweetMap[userId]) - 11 if len(self.tweetMap[userId]) > 11 else -1, -1):
            heapq.heappush(pq ,(-self.tweetMap[userId][i][1],self.tweetMap[userId][i][0]))
        ans = []
        while len(ans) < 10 and pq:
            ans.append(heapq.heappop(pq)[1])
        return ans


    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId not in self.followMap:
            self.followMap[followerId] = set()
        print(self.followMap[followerId])
        self.followMap[followerId].add(followeeId)            


    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.followMap[followerId].discard(followeeId)
        
