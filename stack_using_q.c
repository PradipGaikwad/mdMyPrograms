

// two queues q1 and q2 
stack.push();
stack.pop();
stack.top();


q.push();
q.pop();
q.front();


stack.push(int stack_element) {

    while(!q1.empty()) {
        q2.push(q1.top());
        q1.pop();
    }
 
    q1.push(stack_element);

    while(!q2.empty()) {
        q1.push(q2.top);
        q2.pop();
    }
}


stack.pop() {
    q1.pop();
}

stack.top() {
    return q1.front();
}


