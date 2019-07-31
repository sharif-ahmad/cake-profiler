pipeline {
  agent {
    node {
      label 'Linux'
    }

  }
  stages {
    stage('Build') {
      agent {
        node {
          label 'Linux'
        }

      }
      steps {
        sh 'mkdir build'
        sh 'cd build'
        sh 'cmake ..'
        sh 'cmake --build .'
      }
    }
  }
}