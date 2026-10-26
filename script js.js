// WebDev - Member Registration
// SPI 2201 - Web Application Development I

// style.css styles body.dark
const DARK_CLASS = "dark";

// ===== Step 2: Grab DOM references =====
const form = document.getElementById("regform");

const inputs = {
  name: document.getElementById("name"),
  email: document.getElementById("email"),
  password: document.getElementById("password"),
  confirm: document.getElementById("confirm-password"),
  gender: document.getElementById("gender"),
  dob: document.getElementById("dob"),
  country: document.getElementById("country"),
  phone: document.getElementById("phone"),
  bio: document.getElementById("bio"),
};

const errors = {
  name: document.getElementById("nameError"),
  email: document.getElementById("emailError"),
  password: document.getElementById("passwordError"),
  confirm: document.getElementById("confirmError"),
  gender: document.getElementById("genderError"),
  dob: document.getElementById("dobError"),
  country: document.getElementById("countryError"),
  phone: document.getElementById("phoneError"),
  bio: document.getElementById("bioError"),
};

const successMsg = document.getElementById("successMsg");
const memberList = document.getElementById("memberList");
const emptyNote = document.getElementById("emptyNote");
const countEl = document.getElementById("count");
const themeBtn = document.getElementById("theme");

// Confirm everything was found (anything null means a wrong id)
console.log("form:", form);
console.log("inputs:", inputs);
console.log("errors:", errors);
console.log("successMsg:", successMsg);
console.log("memberList:", memberList);
console.log("count:", countEl);
console.log("theme button:", themeBtn);

// ===== Step 4: Validation rules =====
// Each returns an error message, or "" when the value is valid.
const validators = {
  name(v) {
    v = v.trim();
    if (!v) return "Full name is required.";
    if (v.length < 3) return "Name must be at least 3 characters.";
    if (!/^[A-Za-z][A-Za-z\s'.-]*$/.test(v)) return "Name can only contain letters and spaces.";
    return "";
  },
  email(v) {
    v = v.trim();
    if (!v) return "Email is required.";
    if (!/^[^\s@]+@[^\s@]+\.[^\s@]{2,}$/.test(v)) return "Enter a valid email address.";
    return "";
  },
  password(v) {
    if (!v) return "Password is required.";
    if (v.length < 8) return "Password must be at least 8 characters.";
    if (!/[A-Za-z]/.test(v) || !/\d/.test(v)) return "Use at least one letter and one number.";
    return "";
  },
  confirm(v) {
    if (!v) return "Please confirm your password.";
    if (v !== inputs.password.value) return "Passwords do not match.";
    return "";
  },
  gender(v) {
    return v ? "" : "Please select a gender.";
  },
  dob(v) {
    if (!v) return "Date of birth is required.";
    const dob = new Date(v);
    const today = new Date();
    if (dob > today) return "Date of birth cannot be in the future.";
    let age = today.getFullYear() - dob.getFullYear();
    const m = today.getMonth() - dob.getMonth();
    if (m < 0 || (m === 0 && today.getDate() < dob.getDate())) age--;
    if (age < 16) return "You must be at least 16 years old.";
    return "";
  },
  country(v) {
    v = v.trim();
    if (!v) return "Country is required.";
    if (v.length < 2) return "Enter a valid country.";
    return "";
  },
  phone(v) {
    v = v.trim();
    if (!v) return "Phone number is required.";
    if (!/^\+?\d{9,15}$/.test(v.replace(/[\s-]/g, ""))) return "Enter a valid phone number (9-15 digits).";
    return "";
  },
  bio(v) {
    v = v.trim();
    if (!v) return "Bio is required.";
    if (v.length < 10) return "Bio must be at least 10 characters.";
    if (v.length > 200) return "Bio must be 200 characters or less.";
    return "";
  },
};

// Validate one field and show its message in the matching .error span
function validateField(key) {
  const message = validators[key](inputs[key].value);
  errors[key].textContent = message;
  inputs[key].classList.toggle("invalid", message !== "");
  return message === "";
}

function validateAll() {
  let allValid = true;
  let firstInvalid = null;
  for (const key in inputs) {
    if (!validateField(key)) {
      allValid = false;
      if (!firstInvalid) firstInvalid = inputs[key];
    }
  }
  if (firstInvalid) firstInvalid.focus();
  return allValid;
}

// ===== Step 5: Clear errors as the user fixes them =====
function clearError(key) {
  errors[key].textContent = "";
  inputs[key].classList.remove("invalid");
}

for (const key in inputs) {
  const eventName = inputs[key].tagName === "SELECT" ? "change" : "input";
  inputs[key].addEventListener(eventName, () => {
    clearError(key);
    // Editing the password invalidates an earlier confirm error
    if (key === "password" && inputs.confirm.value) clearError("confirm");
  });
}

// ===== Step 6 & 7: Register a member and update the counter =====
function updateCount() {
  const total = memberList.querySelectorAll("li:not(#emptyNote)").length;
  countEl.textContent = total;
  emptyNote.classList.toggle("hidden", total > 0);
}

function addMember(member) {
  const li = document.createElement("li");
  li.className = "member-item";

  const info = document.createElement("div");
  info.className = "info";

  const nameEl = document.createElement("strong");
  nameEl.textContent = member.name;

  const detailEl = document.createElement("span");
  detailEl.textContent = `${member.email} · ${member.country}`;

  info.append(nameEl, detailEl);

  // ===== Step 9: Remove a member =====
  const removeBtn = document.createElement("button");
  removeBtn.type = "button";
  removeBtn.className = "remove";
  removeBtn.textContent = "Remove";
  removeBtn.addEventListener("click", () => {
    li.remove();
    updateCount();
  });

  li.append(info, removeBtn);
  memberList.appendChild(li);
  updateCount();
}

// ===== Step 8: Success message and reset =====
let successTimer;
function showSuccess(name) {
  successMsg.textContent = `Welcome, ${name}! You have been registered successfully.`;
  successMsg.classList.remove("hidden");
  clearTimeout(successTimer);
  successTimer = setTimeout(() => successMsg.classList.add("hidden"), 4000);
}

// ===== Step 3: Capture the form submission =====
form.addEventListener("submit", (event) => {
  event.preventDefault();
  successMsg.classList.add("hidden");

  if (!validateAll()) return;

  const member = {
    name: inputs.name.value.trim(),
    email: inputs.email.value.trim(),
    country: inputs.country.value.trim(),
  };

  addMember(member);
  showSuccess(member.name);
  form.reset();
  for (const key in inputs) clearError(key);
});

// ===== Step 10: Dark Mode toggle =====
themeBtn.addEventListener("click", () => {
  const isDark = document.body.classList.toggle(DARK_CLASS);
  themeBtn.textContent = isDark ? "Light Mode" : "Dark Mode";
});

// Set the initial counter state
updateCount();