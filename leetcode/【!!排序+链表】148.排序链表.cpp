//
// Created by lenovo on 2021/6/6.
//
///插入排序应该非常简单，但是就是慢了点



///归并排序！
class Solution {
        public:
        ListNode* sortList(ListNode* head) {
            if (!head || !head->next) return head;
            auto slow = head, fast = head;
            while (fast->next && fast->next->next)
                slow = slow->next, fast = fast->next->next;
            // 切链
            fast = slow->next, slow->next = nullptr;
            return merge(sortList(head), sortList(fast));
        }

        private:
        ListNode* merge(ListNode* l1, ListNode* l2) {
            ListNode sub(0), *ptr = &sub;
            while (l1 && l2) {
                auto &node = l1->val < l2->val ? l1 : l2;
                ptr = ptr->next = node, node = node->next;
            }
            ptr->next = l1 ? l1 : l2;
            return sub.next;
        }
};

///快速排序
///这题快排简单啊，因为是链表，只需要将一次partition中，小于head的拿出来就行了，不用换来换去
class Solution {
        public ListNode sortList(ListNode head) {
            if(head==null||head.next==null) return head;
            // 没有条件，创造条件。自己添加头节点，最后返回时去掉即可。
            ListNode newHead=new ListNode(-1);
            newHead.next=head;
            return quickSort(newHead,null);
        }
        // 带头结点的链表快速排序
        private ListNode quickSort(ListNode head,ListNode end){
            if (head==end||head.next==end||head.next.next==end) return head;
            // 将小于划分点的值存储在临时链表中
            ListNode tmpHead=new ListNode(-1);
            // partition为划分点，p为链表指针，tp为临时链表指针
            ListNode partition=head.next,p=partition,tp=tmpHead;
            // 将小于划分点的结点放到临时链表中
            while (p.next!=end){
                if (p.next.val<partition.val){
                    tp.next=p.next;
                    tp=tp.next;
                    p.next=p.next.next;
                }else {
                    p=p.next;
                }
            }
            // 合并临时链表和原链表，将原链表接到临时链表后面即可
            tp.next=head.next;
            // 将临时链表插回原链表，注意是插回！（不做这一步在对右半部分处理时就断链了）
            head.next=tmpHead.next;
            quickSort(head,partition);
            quickSort(partition,end);
            // 题目要求不带头节点，返回结果时去除
            return head.next;
        }
}


/**
 * 排序链表
 *
 *
 * */