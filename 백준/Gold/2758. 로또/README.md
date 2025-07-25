# [Gold IV] 로또 - 2758 

[문제 링크](https://www.acmicpc.net/problem/2758) 

### 성능 요약

메모리: 2380 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 6월 19일 09:58:33

### 문제 설명

<p>선영이는 매주 엄청난 돈을 로또에 투자한다. 선영이가 하는 로또는 1부터 m까지 숫자 중에 n개의 수를 고르는 로또이다.</p>

<p>이렇게 열심히 로또를 하는데, 아직까지 한 번도 당첨되지 않은 이유는 수를 고를 때 각 숫자는 이전에 고른 수보다 적어도 2배가 되도록 고르기 때문이다.</p>

<p>예를 들어, n=4, m=10일 때, 선영이는 다음과 같이 고를 수 있다.</p>

<ul>
	<li>1 2 4 8</li>
	<li>1 2 4 9</li>
	<li>1 2 4 10</li>
	<li>1 2 5 10</li>
</ul>

<p>따라서 선영이는 로또를 4개 산다. </p>

<p>선영이는 돈이 엄청나게 많기 때문에, 수를 고르는 방법의 수 만큼 로또를 구매하며, 같은 방법으로 2장이상 구매하지 않는다.</p>

<p>n과 m이 주어졌을 때, 선영이가 구매하는 로또의 개수를 출력하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 n과 m으로 이루어져 있다.</p>

### 출력 

 <p>각 테스트 케이스에 대해 선영이가 로또를 몇 개나 구매하는지 한 줄에 하나씩 출력한다.</p>

