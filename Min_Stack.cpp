#include <stack>

using namespace std;

class MinStack {
public:
	void push(int x) {
		if (m_minst.empty() || x <= m_minst.top())
			m_minst.push(x);
		m_st.push(x);
	}

	void pop() {
		if (!m_minst.empty() && m_st.top() == m_minst.top())
			m_minst.pop();
		m_st.pop();
	}

	int top() {
		return m_st.top();
	}

	int getMin() {
		return m_minst.top();
	}
private:
	stack<int> m_st;
	stack<int> m_minst;
};
