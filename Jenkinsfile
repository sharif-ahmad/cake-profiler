pipeline {
  agent any
  stages {
    stage('Build') {
      agent {
        dockerfile {
          filename 'Dockerfile'
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