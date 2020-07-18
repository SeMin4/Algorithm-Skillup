# 👩🏻‍💻 GitHub 사용법

### 1. 먼저 자신의 컴퓨터에 Git을 설치한다. 

* [Git 설치](https://git-scm.com/)

* Git 설치 방법은 구글링을 통해 참고
### 2. Git config 를 통해 자신의 로컬 환경에 Git 세팅

* Git 설치를 완료 했다면 git config를 통해 자기 컴퓨터에 Git 환경을 세팅합니다.
* Git config 는 git commit시 등록되는 이메일과 이름 정보등을 등록하는 과정입니다.

```
git config --global user.name "SeMin4"
git config --global user.email "ohsemin4@gmail.com"
```

* Git config 설정을 완료 했다면 `git config --list` 명령어로 확인합니다.


### 3. Github 에서 자기자신의 계정에 repository를 만들기 위해 이 repository를 fork 진행

* 화면 우측상단에 있는 fork를 통해 개인 계정에 repository를 생성 합니다.

![fork](https://user-images.githubusercontent.com/41224549/87819398-1f649300-c8a7-11ea-87e0-fc31415f2aa6.PNG)


### 4. 최초 1번만 개인 계정에 있는 repository에서 clone을 통해 자기 컴퓨터 로컬 환경에 repository 복제(이 repository가 아니라 개인계정에 fork한 repository임!!)

* 안에 있는 링크를 복사하여 git clone을 진행합니다.(주의!! 주소창에 링크 아님!!)

![clone](https://user-images.githubusercontent.com/41224549/87819921-10caab80-c8a8-11ea-84e4-ea12eb31bfe1.PNG)

```
git clone https://github.com/SeMin4/Algorithm-Skillup.git(자신 계정의 repository 주소)
```

### 5. fork한 repository와 원격 repository를 동기화

* 먼저 clone된 로컬 저장소로 이동합니다.
```
$ cd Algorithm-Skillup
```

* 그 저장소에서 remote에 원본 저장소를 등록합니다.
```
$ git remote add mainrepo[원본 저장소 별칭] https://github.com/SeMin4/Algorithm-Skillup.git(원본 repository 주소)
```

### 6. 각각 문제의 폴더에 자기 자신의 폴더를 만들고 알고리즘 풀이를 진행

### 7. 새로 생긴 파일을 stage에 add 후 push 까지 진행

```
$ git add .//전체 변경 내용 스테이지 등록
$ git commit -m "커밋 메시지"//커밋 등록
$ git push orgin master // 자기 계정의 원격 repository에 push 
```

### 8. 원본 저장소에 자기자신의 코드를 PR(pull request)을 통해 반영

* 자기 자신의 저장소로 이동하여 pull requeset를 등록합니다.

![pr](https://user-images.githubusercontent.com/41224549/87844918-e0f9c300-c8fc-11ea-8858-c766c3471a47.PNG)

* new pull request를 누르고 왼쪽에는 원본 저장소와 master branch 선택, 오른쪽에는 head에 본인 repository와 compare에 master 브랜치를 선택 합니다.

![pr2](https://user-images.githubusercontent.com/41224549/87844991-beb47500-c8fd-11ea-8aeb-3841d9c9519d.PNG)

* Create pul request 버튼을 클릭하여 타이틀과 내용을 작성하고 pull reuqest 등록합니다.

### 9. pull request 승인이 되면 자기 자신의 내용이 원본에 잘 올라 갔는지 확인

### 10. 다음번 문제를 풀기전 꼭 원본 저장소에서 pull 을 받아 자신의 repository와 동기화가 잘 됬는지 확인!!

```
$ git pull mainorepo[원본 저장소 별칭] master(원격에 있는 원본 저장소에 있는 것을 가져옴)
```

---

## :octocat: Sourcetree를 이용하여 진행하기

**~~Sourcetree의 버전이 다를 수 있으니 주의!!~~**

### Sourcetree를 통해 개인 repository를 클론을 진행후 Sourcetree에 5번 부터 진행하는 과정

* 설정을 들어간 후 원격(Remote) 탭에서 추가를 클릭합니다.

![sourcetree](https://user-images.githubusercontent.com/41224549/87845217-7185d280-c900-11ea-9722-dafe92a9d833.PNG)

* 다음과 같이 원격 이름(원본 저장소 별칭) URL(원본 저장소 URL 등록) 을 입력합니다.
![remoteadd](https://user-images.githubusercontent.com/41224549/87845271-d8a38700-c900-11ea-8e77-59ef99244467.PNG)

### 6~9번 까지 SourceTree에서 자기 자신의 repository에 올리던 방식과 동일하게 진행

### 다음번 문제를 풀기전 꼭 원본 저장소에서 pull 을 받아 자신의 repository와 동기화가 잘 됬는지 확인!!
* pull을 클릭후 원격 저장소에서 가져오기 부분에서 mainrepo[원본 저장소 별칭] 을 클릭하고 pull을 진행하여 확인합니다.

![image](https://user-images.githubusercontent.com/41224549/87845347-67b09f00-c901-11ea-9ac2-083e0c64ba41.png)


