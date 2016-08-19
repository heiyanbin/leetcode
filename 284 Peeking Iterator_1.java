// 284
// Peeking Iterator
// https://leetcode.com//problems/peeking-iterator/
// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> it;
    Integer current;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    this.it = iterator;
	    current = null;
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if (null != current) return current;
        current = it.next();
        return current;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if (null != current) {
	        Integer ret = current;
	        current = null;
	        return ret;
	    }
	    else {
	        return it.next();
	    }
	}

	@Override
	public boolean hasNext() {
	    return current != null || it.hasNext();
	}
}