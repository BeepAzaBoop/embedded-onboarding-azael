# Work for section 00

Estimated completion time: 1 hour.

## 0. Before you start:

While not required, we recommend you buy your own microcontroller to test out certain parts of the onboarding as you go along.

Many of the tutorials are written around this microcontroller: the `STM32F030R8` chip on the `NUCLEO-F030R8` board package. They're about $11.

You can buy one here: [Buy NUCLEO-F030R8 at Digikey](https://www.digikey.com/en/products/detail/stmicroelectronics/NUCLEO-F030R8/4695526).

As an engineering student, it's good to have one on hand anyways.

## 1. Make a GitHub account if you don't have one.

Use whatever email you prefer. If you lose access to the account and email, your work will be very hard to recover.

## 2. From the website, fork this repository to your account.

From the website: https://github.com/DallasFormulaRacing/embedded-onboarding

## 3. Install git.

There are mamy ways to do this. As long as it makes it to your `usr/bin` or can run from the terminal, it will work.

## 4. Using your terminal skills, navigate to a directory of your choosing.

Make sure this directory is safe, accessible, and ideally, built into your computer (not an external device).

You will clone the forked repository into this directory in this next step so make sure you're okay with having the repository here.

## 5. Set up your local git creditials.

Git will sometimes need credentials from the user in order to perform operations. Also, GitHub stopped accepting password-based HTTPS. You’ll need a [personal access token](https://github.com/settings/tokens).

## 6. Clone the repository to your local.

Make sure its the right one; not the template. Open this in the website or in VSCode. On VSCode, you can press CTRL+SHIFT+V or CMD+SHIFT+V to enter Markdown preview mode.

## 7. Submit for Section 00

Check your work:

Run `git status` in the directory of the repo. You shouldnt get any errors.

Run `git remote -v` in the directory. You should get links to repositories that **have your username in them**. If the link says `github.com/DallasFormulaRacing/...`, you got it wrong.

### -> TO DO <-

1\. Use your terminal skills and create a file called `submit.md` **inside** the `section-00` folder (if youre not reading this on github.com, you're in it already).

2\. Inside that file `submit.md` answer the following questions:

- Run a command line terminal that does both of the following:
  - lists **all** files in the parent directory (`..`) **and**
  - only prints files that match the expression `\.git`.
- What command did you run?

- After running that command, you should see 3 (or 4) files. What files do you see?

3\. Use the Git command-line tools to

- First check the `status` of your repository's git to make sure you didn't touch anything you shouldn't have. Only the appropriate files should show up here.

- Then `add` your changes to a stage that you made to this repository.

- Then `commit` those changes with an appropriate message.

- Finally, `push` to the origin to finalize your work here.

- Don't be afraid to look this up if you have to.

4\. You are done with section 0.

- Open this repository in an editor of your choice. I recommend VS Code.

# References:

[1] https://git-scm.com/docs/gitcredentials

# Most Common Mistakes

- **Cloning the template instead of your fork**

  Check the URL. It should have _your_ GitHub username in it.

- **Skipping Git config**

  If your commits show up as “unknown” or can’t be pushed, it’s probably because you didn’t set your name/email or your credentials are wrong.

- **Trying to use Git without installing it**

  Install git.

- **Cloning into a weird directory**

  Network drives, external drives, or synced folders (like OneDrive or iCloud) are not recommended for this. Use your local disk.

- **Running `rm -rf` (or any command for that matter) without thinking**

  Do not do this. Never run a command before knowing exactly what it does.
