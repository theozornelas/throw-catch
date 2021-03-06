Qt Desktop Template with Testing
--------
[![Build Status](https://travis-ci.org/theozornelas/throw-catch.svg?branch=develop)](https://travis-ci.org/theozornelas/throw-catch)

A Qt Desktop Application template which allows for the developer to utilize the Qt testing features.

# Instructions

### Cloning the Repo

When you `git clone` the repository, make sure to rename the repo it is going into that what ever name you want

    git clone https://github.com/EDKarlsson/qt-app-with-testing-template/ ${name-of-my-app}

In the `defaults.pri` change the Qt environment variable APP_NAME to the name of the application you are making.

If it is failing on compile:
> Make sure to go through all the `.pro` files to replace the name `qt-application-testing-template` (or anything similar) with the name that you used for `${name-of-my-app}`

### TravisCI
Within the TravisCI file, you can remove all the different versions of Qt you don't want TravisCI to compile for.

For example to remove 51, remove:
```yml
- QT_BASE=51
...
- if [ "$QT_BASE" = "51" ]; then sudo add-apt-repository ppa:beineri/opt-qt511-trusty -y; fi
...
- if [ "$QT_BASE" = "51" ]; then sudo apt-get install -qq qt51base; source /opt/qt51/bin/qt51-env.sh; fi
```

Free to use by anyone who would like to and please feel free to make pull requests to correct or add features to this.

> Create by Dan Karlsson
