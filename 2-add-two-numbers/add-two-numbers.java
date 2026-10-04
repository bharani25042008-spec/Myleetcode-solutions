/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
 import java.util.ArrayList;
 import  java.math.BigInteger;
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode temp=l1;
            ListNode tmp=l2;
            String s1="";
            String s2="";
            while(temp!=null)
            {
                s1+=temp.val;
                temp=temp.next;
            }
            while(tmp!=null)
            {
                s2+=tmp.val;
                tmp=tmp.next;
            }
            String ans="";
            String res="";
            for(int i=s1.length()-1;i>=0;i--)
            {
                ans+=s1.charAt(i);
            }
            for(int i=s2.length()-1;i>=0;i--)
            {
                res+=s2.charAt(i);
            }
            BigInteger num1=new BigInteger(ans);
            BigInteger num2=new BigInteger(res);
            BigInteger n=num1.add(num2);
            String fin=n.toString();
            String s="";
            for(int i=fin.length()-1;i>=0;i--)
            {
                s+=fin.charAt(i);
            }
            ListNode head=null;
            ListNode tail=null;
            for(int i=0;i<s.length();i++)
            {
                ListNode newnode=new ListNode(s.charAt(i)-'0');
                if(head==null)
                {
                    head=newnode;
                    tail=newnode;
                }
                else{
                    tail.next=newnode;
                    tail=newnode;
                    
                }
            }
       return head;
    }
}