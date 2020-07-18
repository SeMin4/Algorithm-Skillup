# 👩🏻‍💻 GitHub 사용법

### 1. 먼저 자신의 컴퓨터에 Git을 설치한다. 

* [Git 설치](https://git-scm.com/)

* Git 설치 방법은 구글링을 통해 참고
### 2. Git config 를 통해 자신의 로컬 환경에 Git 세팅

* Git 설치를 완료 했다면 git config를 통해 자기 컴퓨터에 Git 환경을 세팅
* Git config 는 git commit시 등록되는 이메일과 이름 정보등을 등록하는 과정

```
git config --global user.name "SeMin4"
git config --global user.email "ohsemin4@gmail.com"
```

* Git config 설정을 완료 했다면 `git config --list` 명령어로 확인


### 3. Github 에서 자기자신의 계정에 repository를 만들기 위해 이 repository를 fork 진행

* 화면 우측상단에 있는 fork를 통해 개인 계정에 repository를 생성 

![fork](https://user-images.githubusercontent.com/41224549/87819398-1f649300-c8a7-11ea-87e0-fc31415f2aa6.PNG)


### 4. 최초 1번만 개인 계정에 있는 repository에서 clone을 통해 자기 컴퓨터 로컬 환경에 repository 복제(이 repository가 아니라 개인계정에 fork한 repository임!!)

* 안에 있는 링크를 복사하여 git clone을 진행(주의!! 주소창에 링크 아님!!)

![clone](https://user-images.githubusercontent.com/41224549/87819921-10caab80-c8a8-11ea-84e4-ea12eb31bfe1.PNG)


### 5. fork한 repository와 원격 repository를 동기화