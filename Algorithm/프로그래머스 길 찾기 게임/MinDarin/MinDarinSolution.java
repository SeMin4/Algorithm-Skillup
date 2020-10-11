import java.util.*;

public class Solution {
	public static int[][] solution(int[][] nodeinfo) 
	{
		int[][] answer = new int[2][nodeinfo.length];
    	TreeSet<node> tree = new TreeSet<node>();
    	int N = nodeinfo.length;
    	int count = 0;
    	for(int[] i : nodeinfo)
    	{
    		node n = new node(i[0],i[1],++count);
    		tree.add(n);
    	}
    	node root = tree.pollFirst();
    	Iterator it = tree.iterator();
    	while(it.hasNext())
    	{
    		makeTree(root, (node)it.next());
    	}
    	
    	LinkedList<Integer> prelist = new LinkedList();
    	pre(prelist,root);
    	
    	LinkedList<Integer> postlist = new LinkedList();
    	post(postlist,root);

    	Iterator preit  = prelist.iterator();
    	Iterator postit = postlist.iterator();
    	
    	int answer_idx = 0;
    	while(preit.hasNext() && postit.hasNext())
    	{
    		answer[0][answer_idx] = (int) preit.next();
    		answer[1][answer_idx++] = (int) postit.next();
    	}
    	return answer;
    }
	
	public static void pre(LinkedList<Integer> list,node temp)
	{

		if(temp == null)
		{
			return;
		}
		list.add(temp.idx);
		pre(list, temp.leftChild);
		pre(list, temp.rightChild);

   }
	
	public static void post(LinkedList<Integer> list,node temp)
	{
		if(temp == null)
		{
			return;
		}
		
		post(list, temp.leftChild);
		post(list, temp.rightChild);

		list.add(temp.idx);
   }

  public static void pre(int idx,node[] arr,LinkedList list)
  {
  	if(arr[idx] == null)
  	{
  		return ;
  	}
  	list.add( arr[idx].idx);
  	pre(idx*2,arr,list);
  	pre(idx*2+1,arr,list);
  }
	public static void makeTree(node parent, node child)
	{
		if(parent.x > child.x)
		{
			if(parent.leftChild == null)
				parent.leftChild = child;
			else
				makeTree(parent.leftChild, child);
		}
		else
		{
			if(parent.rightChild == null)
				parent.rightChild = child;
			else
				makeTree(parent.rightChild, child);			
		}
	}
    public static void main(String[] args)
    {
    	int[][] nodeinfo = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
    	System.out.println(solution(nodeinfo));
    }
    
}
class node implements Comparable<node>
{
	int x;
	int y;
	int idx;
	node leftChild = null;
	node rightChild = null;
	node(int i, int j , int k)
	{
		x = i;
		y = j;
		idx = k;
	}
	@Override
	public int compareTo(node n1)
	{
		if(this.y > n1.y)
			return -1;
		else if(this.y < n1.y)
			return 1;
		else
		{
			if(this.x < n1.x)
				return -1;
			else if(this.x > n1.x)
				return 1;
			else return 0;
		}
	}
}
//class myc implements Comparator<node>
//{
//	@Override
//	public int compare(node o1, node o2) {
//		if(o1.y < o2.y)
//			return -1;
//		else if(o1.y > o2.y)
//			return 1;
//		else
//		{
//			if(o1.x < o2.y)
//				return -1;
//			else if (o1.x > o2.x)
//				return 1;
//			else
//				return 0;
//		}
//	}	
//}
