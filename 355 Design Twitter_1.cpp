// 355
// Design Twitter
// https://leetcode.com//problems/design-twitter/
class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		tweets[userId].push_back(make_pair(tweetId, time++));
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<vector<pair<int, int>>*> sources;
		auto it = tweets.find(userId);
		if (it != tweets.end() && !it->second.empty()) {
			sources.push_back(&it->second);
		}
		for (int followeeId : follows[userId]) {
			it = tweets.find(followeeId);
			if (it != tweets.end() && !it->second.empty()) {
				sources.push_back(&it->second);
			}
		}

		priority_queue<pair<int, int>> pq;
		vector<int> p(sources.size());
		for (int i = 0; i < sources.size(); ++i) {
		    p[i] = sources[i]->size() - 1;
			pq.push(make_pair((*sources[i])[p[i]].second, i));
		}

		vector<int> ans;
		for (int i = 0; i < 10 && pq.size() > 0; ++i) {
			auto source = pq.top(); pq.pop();
			ans.push_back((*sources[source.second])[p[source.second]].first);
			p[source.second] -= 1;
			if (p[source.second] >= 0) {
				pq.push(make_pair((*sources[source.second])[p[source.second]].second, source.second));
			}
		}
		return ans;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
	    if (followerId == followeeId) return;
		follows[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		follows[followerId].erase(followeeId);
	}

private:
	map<int, set<int>> follows;
	map<int, vector<pair<int, int>>> tweets;
	int time = 1;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */